/*
 * Copyright (C) 2008 Apple Inc. All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 *
 * 1.  Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer. 
 * 2.  Redistributions in binary form must reproduce the above copyright
 *     notice, this list of conditions and the following disclaimer in the
 *     documentation and/or other materials provided with the distribution. 
 * 3.  Neither the name of Apple Computer, Inc. ("Apple") nor the names of
 *     its contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission. 
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE AND ITS CONTRIBUTORS "AS IS" AND ANY
 * EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED
 * WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL APPLE OR ITS CONTRIBUTORS BE LIABLE FOR ANY
 * DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES
 * (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 * LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND
 * ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 * (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF
 * THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 */

/*
* This file was modified by Electronic Arts Inc Copyright � 2009-2010
*/

#ifndef WTF_ThreadSpecific_h
#define WTF_ThreadSpecific_h

#include <wtf/FastAllocBase.h>
#include <wtf/Noncopyable.h>

#if USE(PTHREADS) || PLATFORM(WIN)
// Windows currently doesn't use pthreads for basic threading, but implementing destructor functions is easier
// with pthreads, so we use it here.
#include <pthread.h>
#endif

namespace WTF {

template<typename T> class ThreadSpecific : Noncopyable {
public:
#if NO_MACRO_NEW
	// Placement operator new.
        void* operator new(size_t, void* p) { return p; }
        void* operator new[](size_t, void* p) { return p; }

        void* operator new(size_t size)
        {
            void* p = fastMalloc(size);
            fastMallocMatchValidateMalloc(p, WTF::Internal::AllocTypeClassNew);
            return p;
        }

        void operator delete(void* p)
        {
            fastMallocMatchValidateFree(p, WTF::Internal::AllocTypeClassNew);
            fastFree(p);  // We don't need to check for a null pointer; the compiler does this.
        }

        void* operator new[](size_t size)
        {
            void* p = fastMalloc(size);
            fastMallocMatchValidateMalloc(p, WTF::Internal::AllocTypeClassNewArray);
            return p;
        }

        void operator delete[](void* p)
        {
            fastMallocMatchValidateFree(p, WTF::Internal::AllocTypeClassNewArray);
            fastFree(p);  // We don't need to check for a null pointer; the compiler does this.
        }
#endif //NO_MACRO_NEW
public:
    ThreadSpecific();
    T* operator->();
    operator T*();
    T& operator*();
    ~ThreadSpecific();

private:
    T* get();
    void set(T*);
    void static destroy(void* ptr);

#if USE(PTHREADS) || PLATFORM(WIN)
    struct Data : Noncopyable {
public:
#if NO_MACRO_NEW
	// Placement operator new.
        void* operator new(size_t, void* p) { return p; }
        void* operator new[](size_t, void* p) { return p; }

        void* operator new(size_t size)
        {
            void* p = fastMalloc(size);
            fastMallocMatchValidateMalloc(p, WTF::Internal::AllocTypeClassNew);
            return p;
        }

        void operator delete(void* p)
        {
            fastMallocMatchValidateFree(p, WTF::Internal::AllocTypeClassNew);
            fastFree(p);  // We don't need to check for a null pointer; the compiler does this.
        }

        void* operator new[](size_t size)
        {
            void* p = fastMalloc(size);
            fastMallocMatchValidateMalloc(p, WTF::Internal::AllocTypeClassNewArray);
            return p;
        }

        void operator delete[](void* p)
        {
            fastMallocMatchValidateFree(p, WTF::Internal::AllocTypeClassNewArray);
            fastFree(p);  // We don't need to check for a null pointer; the compiler does this.
        }
#endif //NO_MACRO_NEW
		Data(T* value, ThreadSpecific<T>* owner) : value(value), owner(owner) {}

        T* value;
        ThreadSpecific<T>* owner;
    };

    pthread_key_t m_key;
#endif
};

#if USE(PTHREADS) || PLATFORM(WIN)
template<typename T>
inline ThreadSpecific<T>::ThreadSpecific()
{
    pthread_key_create(&m_key, destroy);
}

template<typename T>
inline ThreadSpecific<T>::~ThreadSpecific()
{
    pthread_key_delete(m_key); // Does not invoke destructor functions.
}

template<typename T>
inline T* ThreadSpecific<T>::get()
{
    Data* data = static_cast<Data*>(pthread_getspecific(m_key));
    return data ? data->value : 0;
}

template<typename T>
inline void ThreadSpecific<T>::set(T* ptr)
{
    ASSERT(!get());
    pthread_setspecific(m_key, new Data(ptr, this));
}

template<typename T>
inline void ThreadSpecific<T>::destroy(void* ptr)
{
    Data* data = static_cast<Data*>(ptr);
    pthread_setspecific(data->owner->m_key, 0);
    delete data->value;
    delete data;
}

#else
#error ThreadSpecific is not implemented for this platform.
#endif

template<typename T>
inline ThreadSpecific<T>::operator T*()
{
    T* ptr = static_cast<T*>(get());
    if (!ptr) {
        ptr = new T();
        set(ptr);
    }
    return ptr;
}

template<typename T>
inline T* ThreadSpecific<T>::operator->()
{
    return operator T*();
}

template<typename T>
inline T& ThreadSpecific<T>::operator*()
{
    return *operator T*();
}

}

#endif
