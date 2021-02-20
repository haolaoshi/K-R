/*
 * Example
 *
 *
 */
typedef long Align;

union header{
    struct {
        union header *ptr;
        unsigned size;

    }s;
    Align x;
};
typedef union header Header;

static Header base;
static Header *freep = NULL;
