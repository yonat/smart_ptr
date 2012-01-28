/*
 * owned_ptr - ownership aware auto-deleting pointer
 *
 * Note: Do not use in an STL container!
 */

#ifndef OWNED_PTR_H
#define OWNED_PTR_H

/* For ANSI-challenged compilers, you may want to #define
 * NO_MEMBER_TEMPLATES, explicit or mutable */

template <class X> class owned_ptr
{
public:
    typedef X element_type;

    explicit owned_ptr(X* p=0) throw()      : itsOwn(p!=0), itsPtr(p) {}
    ~owned_ptr()                            {if (itsOwn) delete itsPtr;}
    owned_ptr(const owned_ptr>& r) throw()
        : itsOwn(r.itsOwn), itsPtr(r.release()) {}
    owned_ptr& operator=(const owned_ptr& r) throw()
    {
        if (&r != this) {
            if (itsPtr != r.itsPtr) {
                if (itsOwn) delete itsPtr;
                itsOwn = r.itsOwn;
            }
            else if (r.itsOwn) itsOwn = true;
            itsPtr = r.release();
        }
        return *this;
    }

#ifndef NO_MEMBER_TEMPLATES
    template <class Y> friend class owned_ptr<Y>;
    template <class Y> owned_ptr(const owned_ptr<Y>& r) throw()
        : itsOwn(r.itsOwn), itsPtr(r.release()) {}
    template <class Y> owned_ptr& operator=(const owned_ptr<Y>& r) throw()
    {
        if (&r != this) {
            if (itsPtr != r.itsPtr) {
                if (itsOwn) delete itsPtr;
                itsOwn = r.itsOwn;
            }
            else if (r.itsOwn) itsOwn = true;
            itsPtr = r.release();
        }
        return *this;
    }
#endif

    X& operator*()  const throw()           {return *itsPtr;}
    X* operator->() const throw()           {return itsPtr;}
    X* get()        const throw()           {return itsPtr;}
    X* release()    const throw()
#ifndef mutable
                                            {itsOwn = false; return itsPtr;}
#else // for ANSI-challenged compilers
        {(const_cast<owned_ptr<X>* >(this))->itsOwn = false; return itsPtr;}
#endif

private:
    mutable bool itsOwn;
    X* itsPtr;
};


#endif // OWNED_PTR_H
