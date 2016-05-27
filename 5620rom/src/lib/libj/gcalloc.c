/* */
/*									*/
/*	Copyright (c) 1985,1986,1987,1988,1989,1990,1991,1992   AT&T	*/
/*			All Rights Reserved				*/
/*									*/
/*	  THIS IS UNPUBLISHED PROPRIETARY SOURCE CODE OF AT&T.		*/
/*	    The copyright notice above does not evidence any		*/
/*	   actual or intended publication of such source code.		*/
/*									*/
/* */
#include <dmd.h>
#include <setup.h>

#define	oops(x, s)	/*if(x)sstep(s)*/
/*
 * Garbage-collecting allocator
 *
 * called as:	gcalloc(nbytes, where)
 *	nbytes is unsigned long
 *	where is a pointer to the location which will point to the area
 *	(e.g. base in a Bitmap), to be updated when necessary
 */

/*
 * The arena is allocated in longs, to speed up compaction
 * Garbage is compacted towards the top (high address end) of the arena,
 * i.e. away from the regular, non-compacting, allocator.
 * A block has a struct header as its top HEADERSIZE longs, and
 * a pointer to the struct header as its bottom long, for use by gcfree.
 * header.caller points to the allocating process so things can be cleaned
 * up when it exits.
 * header.pval points to the USER location where the pointer to the block
 * is stored; this cell must be updated after a compaction.
 * Deallocated blocks have header.pval odd.
 */
#define	STARTAREA	(long *)(allocendp)
#undef nextlong
#undef ENDAREA
#undef NAVAIL
#undef NLONGS
long *nextlong;
long NLONGS, NAVAIL;
long *ENDAREA;
#define nextlong Snextlong
#define NLONGS SNLONGS
#define NAVAIL SNAVAIL
#define ENDAREA SENDAREA
struct header{
	union uuu{
		long	Uival;		/* integer value of where */
		long	**Upval;	/* where */
	}u;
	long	*caller;		/* which process allocated */
	unsigned long nlongs;		/* # of longs in the user's data */
};
#define	ival	u.Uival
#define	pval	u.Upval
#define	HEADERSIZE	sizeof(struct header)/sizeof(long)
#define	hp	((struct header *)p)

#undef gcinit
gcinit()
#define gcinit Sgcinit
{
	ENDAREA= (long *)(maxaddr[VALMAXADDR]-4);
	nextlong = ENDAREA;	/* init; this runs in rom, so .data no good */
}

#undef realgcalloc
char *
realgcalloc(nbytes, where, caller)
#define realgcalloc Srealgcalloc
	register unsigned long nbytes;
	long **where;
	char *caller;	/* really a Proc * */
{
	register retry = 0;
	register long *p;
	
	if((long)caller&1)	/* head off a possible disaster */
		return 0;
	nbytes+=sizeof(long)-1;
	nbytes>>=2;	/* convert bytes to longs */
#define	Nlongs	nbytes
	Nlongs+=HEADERSIZE+1;
	while(nextlong-STARTAREA < Nlongs){
NLONGS=(long *)Nlongs;
NAVAIL=nextlong-STARTAREA;
		if(retry++)
			return 0;
		compact();
	}
	p=nextlong-HEADERSIZE;
	hp->caller=(long *)caller;
	hp->pval=where;
	hp->nlongs=Nlongs-HEADERSIZE-1;
	nextlong-=Nlongs;
	*nextlong=(long)p;	/* so we can find the header when we free */
	return (char *)(*(hp->pval)=nextlong+1);
}
#undef gcalloc
char *
gcalloc(n, w)
#define gcalloc Sgcalloc
	unsigned long n;
	long **w;
{
	return realgcalloc(n, w, (char *)0);
}

#undef gcfree
void
gcfree(cp)
#define gcfree Sgcfree
	register char *cp;
{
#define	p	((long *)cp)
	/* nice and safe */
	oops((p<=nextlong || p>=ENDAREA),"gcfree 1");
	if(p>nextlong && p<ENDAREA){
		cp=(char *)(p[-1]);	/* pointer to the header */
		oops(p<=nextlong || p>=ENDAREA, "gcfree 2");
		if(p>nextlong && p<ENDAREA)
			hp->ival|=1;
	}
#undef	p
}

#undef gcfreeall
gcfreeall(whichproc)
#define gcfreeall Sgcfreeall
	char *whichproc;
{
	register long *p;
	for(p=ENDAREA; p>nextlong; p-=hp->nlongs+1){
		p-=HEADERSIZE;
		oops(hp->caller > nextlong, "gcfreeall 1");
		oops(hp->pval > nextlong, "gcfreeall 2");
		if(hp->caller==(long *)whichproc)
			hp->ival|=1;
	}
}
static
compact()
{
	register long *w, *p;
	register struct header *header;
	register unsigned long n;
	static Rectangle r={0, 0, 50, 50};

	rectf(&display, r, F_XOR);
	w=ENDAREA;
	p=w;
	while(p>nextlong){
		header=(struct header *)(p-HEADERSIZE);
/*
		if(w==p || (header->ival&1)){
			p-= n = header->nlongs+HEADERSIZE+1;
			if((header->ival&1)==0)
				w-=n;
			continue;
		}
*/
		oops(header->caller > nextlong, "compact 1");
		oops(header->pval > nextlong, "compact 2");
		if(header->ival&1){
			p -= header->nlongs+HEADERSIZE+1;
			continue;
		}
		*--w = n = header->nlongs;
		*--w = (long)header->caller;
		*--w = header->ival;
		p-=HEADERSIZE;
		header = (struct header *)w;
		*(((struct header *)w)->pval)=w-n; /* update *where */
		if(n>0) do
			*--w = *--p;
		while(--n);
		--p;
		*--w = (long)header;	/* back pointer to header */
	}
	nextlong=w;
	rectf(&display, r, F_XOR);
}
