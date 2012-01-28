#pragma warning (disable : 4284)

#include "owned_ptr.h"
#include "autocreate_ptr.h"
#include "counted_ptr.h"
#include "copied_ptr.h"
#include "linked_ptr.h"
#include "cow_ptr.h"

int main()
{
    owned_ptr<char> op1(new char('a'));
    owned_ptr<char> op2(op1);
    owned_ptr<char> op3;
    op3 = op2;
    op3 = op1;

    autocreate_ptr<int> ap;
    *ap = 7;

    counted_ptr<char> cp1(new char('a'));
    counted_ptr<char> cp2(cp1);
    counted_ptr<char> cp3;
    cp3 = cp2;
    cp3 = cp1;

    copied_ptr<char> cpp1(new char('a'));
    copied_ptr<char> cpp2(cpp1);
    copied_ptr<char> cpp3;
    cpp3 = cpp2;
    cpp3 = cpp1;

    linked_ptr<char> lp1(new char('a'));
    linked_ptr<char> lp2(lp1);
    linked_ptr<char> lp3;
    lp3 = lp2;
    lp3 = lp1;

    cow_ptr<char> wp1(new char('a'));
    cow_ptr<char> wp2(wp1);
    *wp2 = 'x';

    return 0;
}