
dnl This file is `m4/tree.m4' : m4 macros to autogenerate treem4.h
dnl Tell the user about this.
/* This file was automatically generated from `m4/tree.m4', do not edit! */


/*
 *  treem4.h  --  internal header for libTT objects hierarchy tree
 */

#ifndef _TT_TREEM4_H
#define _TT_TREEM4_H

include(`m4/TThandy.m4h')

#define TT_LIST(el) \
TTlist()

#define TT_NLIST(el) \
TTnlist()

#define super_(obj)	TT_CAT(super_,obj)
#define order_(obj)	TT_CAT(order_,obj)
#define magicmask_(obj)	TT_CAT(magicmask_,obj)
#define magic_(obj)	TT_CAT(magic_,obj)

divert(-1)

dnl now, the nightmare of objects hierarchy

define(`radix16', `0x`'eval(`$1', 16)')

dnl how many objects are descendant of another given object?

define(`shiftword', `patsubst(`$1', `^ *\w+ *', `')')
define(`numwords', `ifelse(`$1', `', 0, `incr(numwords(shiftword(`$1')))')')

dnl initialize child_$1

define(`el', `define(`child_$1')')
TTlist()
undefine(`el')

dnl define super_$1 to parent of $1 and append children of $1 to child_$1

define(`m4super_ttobj', `none')

define(`extends', `define(`child_$1', child_$1 $2)')
define(`field')
define(`el', `TTdef_$1($1)')
TTnlist()
undefine(`el')
define(`field')
define(`extends')


define(`log2', `_log2($1, 0)')
define(`_log2', `ifelse(`$1', 0, `$2', `_log2(eval(`$1'/2), incr(`$2'))')')

define(`exp2m1', `ifelse(`$1', 0, 0, `decr(eval(1<<`$1'))')')


dnl set childN_$1 to # of children of $1

define(`el', `define(`childN_$1', numwords(child_$1))')
TTlist()
undefine(`el')

dnl set childlogN_$1 to log2(childN), rounded up

define(`el', `define(`childlogN_$1', log2(childN_$1))')
TTlist()
undefine(`el')

dnl set magicmaskN_$1 to (childlogN_$1) bits all set to 1

define(`el', `define(`magicmaskN_$1', exp2m1(childlogN_$1)) define(`bitsN_$1', magicmaskN_$1)')
TTlist()
undefine(`el')

dnl add parents' childlogN_$1 to each childlogN_$2
dnl and shift each magicmaskN_$2 by childlogN_$2 and add parents' magicmaskN_$1 to them 

define(`extends', `define(`childlogN_$2', eval(childlogN_$2 + childlogN_$1))
		  define(`magicmaskN_$2', eval((magicmaskN_$2<<childlogN_$1) | magicmaskN_$1))')
define(`field')
define(`el', `TTdef_$1($1)')
TTnlist()
undefine(`el')
define(`field')
define(`extends')



dnl initialize childI_$1

define(`el', `define(`childI_$1', 1)')
TTlist()
undefine(`el')

dnl initialize childPOS_$1 to the position with respect to others in parent's list of children

define(`extends', `define(`childPOS_$2', childI_$1) define(`childI_$1', incr(childI_$1))')
define(`field')
define(`el', `TTdef_$1($1)')
TTnlist()
undefine(`el')
define(`field')
define(`extends')


dnl calculate magicN_$1 as follows:
dnl highest bits are childPOS_$1 (conveniently shifted by parent's parent's childlogN_$1);
dnl lower bits are parents' magicN_$1

define(`childlogN_none', 0)
define(`magicN_ttobj', 0)

define(`el', `define(`magicN_$1', eval((childPOS_$1<<merge(childlogN_,merge(m4super_,m4super_$1))) | merge(magicN_,m4super_$1)))')
TTnlist()
undefine(`el')

divert

/*
 * NOTE:
 *
 * magicmask_* and magic_* are autogenerated using a quite intricated m4 algorythm.
 *
 * the final effect is shown below, on a cutdown hierarchy tree.
 * in the picture, first number is magic_*, second is magicmask_*
 *
 *                         ________ttobj
 *                ________/   ____/(0,0)
 *       ________/       ____/       |
 *      /               /            |
 *ttlistener     ttevent        ttcomponent
 *(0x1,0x3)     (0x2,0x3)     ___(0x3,0x3)___
 *                      _____/    /     \    \_____
 *                _____/         /       \         \_____
 *               /              /         \              \
 *           _ttvisible_   ttbuttongroup   tttheme   ttapplication
 *          /(0x7,0x1F)\\__  (0xB,0x1F)   (0xF,0x1F)  (0x13,0x1F)
 *         /    |       \  \_________
 *        /     |        \           \
 * ttnative   ttwidget   ttmenuitem   ttmenubar
 *(0x27,0xFF)(0x47,0xFF) (0x67,0xFF) (0x87,0xFF)
 *
 * magic_* of a children is the parent's one, plus the progressive number
 * (conveniently shifted) of the children in the parent's children list.
 *
 * as you can see, all children of the same parent share the same magicmask;
 * this magicmask is the smallest bit mask that can hold all children magic_* numbers.
 * in other words, the tree is Huffman coded (node frequencies do not apply in this case)
 *
 * with this setup, runtime type checking and casting is extremely simple:
 * to check if an object of type A can be cast to type B, just do:
 *
 *  if ((magic_A & magicmask_B) == magic_B) {
 *      success;
 *  } else {
 *      fail;
 *  }
 * 
 */

/* set order_xxx enums */
typedef enum e_order_ttobj {
    order_ttobj = 1,
#define el(o) order_(o),
TT_NLIST(el)
#undef el
    order_n
} e_order_ttobj;


/* set magicmask_xxx enums */
typedef enum e_magicmask_ttobj {
    magicmask_ttobj = 0,`'dnl
define(`el', `
    magicmask_$1 = radix16(merge(magicmaskN_,m4super_$1)),')`'dnl
TTnlist()`'dnl
undefine(`el')
    magicmask_last
} e_magicmask_ttobj;


typedef enum e_magic_ttobj {
    magic_ttobj = 0,
define(`el', `
    magic_$1 = radix16(magicN_$1),')
TTnlist()
undefine(`el')
    magic_last
} e_magic_ttobj;


/* #define IS(xxx,o) macros */
#define IS(obj,o) (((o)->FN->magic & magicmask_(obj)) == magic_(obj))


define(`exported_fields', `TTdef_$1($1,$1)')
define(`extends')
define(`exported', `ifelse(`$3', `get', `field(`$1', `$4', r)', `')')
define(`field', `ifelse(`$3', `', `', `
    this`'_$2,')')
define(`el', `define(`this', $1)

    this`'_not_a_value = order_`'this << 16, TThandy_$1($1,$1)')
typedef enum e_value_ttobj {
TTlist()
    value_last
} e_value_ttobj;
define(`field')
undefine(`el')

#endif /* _TT_TREEM4_H */

