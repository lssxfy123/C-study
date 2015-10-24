//  Copyright 2013 xxcig group

#ifndef SINGLETON_HPP
#define SINGLETON_HPP

#include <stdlib.h>
#include <noncopyable.hpp>
// #include <qmutex.h>

// #include <iostream>

namespace xxcig {

/* Copyright (C) Scott Bilas, 2000.
 * All rights reserved worldwide.
 *
 * This software is provided "as is" without express or implied
 * warranties. You may freely copy and compile this source into
 * applications you distribute provided that the copyright text
 * below is included in the resulting source code, for example:
 * "Portions Copyright (C) Scott Bilas, 2000"
 */

template <typename T>
class Singleton: public noncopyable {
  private:
    static void CreateIfNotExist()
    {
        if (!instance_) {
            // QMutexLocker locker(&mutex_);
            if (!instance_) {
                instance_ = new T();
                atexit(destroy);
            }
        }
    }

    static void destroy()
    {
//        std::cout << " Singleton destroy: " << instance_ << std::endl;
        delete instance_;
    }

  protected:
    Singleton()
    {
//        std::cout << " Singleton ctor: " << this << std::endl;
    }
    virtual ~Singleton()
    {
//        std::cout << " Singleton dtor: " << this << std::endl;
    }

  public:
    static T& GetInstance()
    {
        CreateIfNotExist();
        return *instance_;
    }

    static T* GetInstancePtr()
    {
        CreateIfNotExist();
        return instance_;
    }

  private:
    static T* instance_;
    // static QMutex mutex_;
};

template<typename T>
T* Singleton<T>::instance_ = NULL;

// template<typename T>
// QMutex Singleton<T>::mutex_;



// CreationPolicy ------------------------------------------------
// template <class T>
// struct CreateUsingNew
//  {
//      static T* Create() {
//          return new T;
//      }

//      static void Destroy(T* p) {
//          delete p;
//      }
//  };

// template<template<class> class Alloc>
// struct CreateUsing
// {
//     template <class T>
//     struct Allocator
//     {
//         static Alloc<T> allocator;

//         static T* Create() {
//             return new (allocator.allocate(1)) T;
//         }

//         static void Destroy(T* p) {
//             //allocator.destroy(p);
//             p->~T();
//             allocator.deallocate(p,1);
//         }
//    };
// };

// template <class T>
// struct CreateUsingMalloc
// {
//     static T* Create() {
//         void* p = std::malloc(sizeof(T));
//         if (!p) return 0;
//         return new(p) T;
//     }

//     static void Destroy(T* p) {
//         p->~T();
//         std::free(p);
//     }
// };

// template <class T>
// struct CreateStatic
// {

// #ifdef _MSC_VER
// #pragma warning( push )
// #pragma warning( disable : 4121 )
// // alignment of a member was sensitive to packing
// #endif // _MSC_VER

//    union MaxAlign {
//        char t_[sizeof(T)];
//        short int shortInt_;
//       int int_;
//       long int longInt_;
//       float float_;
//       double double_;
//       long double longDouble_;
//       struct Test;
//       int Test::* pMember_;
//       int (Test::*pMemberFn_)(int);
//   };

// #ifdef _MSC_VER
// #pragma warning( pop )
// #endif // _MSC_VER

//     static T* Create() {
//         static MaxAlign staticMemory_;
//         return new(&staticMemory_) T;
//     }

//     static void Destroy(T* p) {
//         p->~T();
//     }
// };

// // LifetimePolicy ------------------------------------------------
// template <class T>
// struct DefaultLifetime
// {
//     static void ScheduleDestruction(T*, atexit_pfn_t pFun) {
//         std::atexit(pFun);
//     }

//     static void OnDeadReference() {
//         throw std::logic_error("Dead Reference Detected");
//     }
// };

// template <class T>
// class PhoenixSingleton
// {
//  public:
//    static void ScheduleDestruction(T*, atexit_pfn_t pFun)
//    {
// #ifndef ATEXIT_FIXED
//         if (!destroyedOnce_)
// #endif
//         {
//             std::atexit(pFun);
//         }
//     }

//     static void OnDeadReference() {
// #ifndef ATEXIT_FIXED
//         destroyedOnce_ = true;
// #endif
//     }

//   private:
// #ifndef ATEXIT_FIXED
//     static bool destroyedOnce_;
// #endif
// };

// #ifndef ATEXIT_FIXED
// template <class T>
// bool PhoenixSingleton<T>::destroyedOnce_ = false;
// #endif

// template <class T>
// class DeletableSingleton
// {
//   public:
//     static void ScheduleDestruction(T*, atexit_pfn_t pFun) {
//        static bool firstPass = true;
//        isDead = false;
//        deleter = pFun;
//        if (firstPass || needCallback) {
//            std::atexit(atexitCallback);
//            firstPass = false;
//            needCallback = false;
//        }
//    }

//    static void OnDeadReference() {}

//    static void GracefulDelete() {
//        if (isDead) {
//            return;
//        }
//        isDead = true;
//        deleter();
//    }

//  protected:
//    static atexit_pfn_t deleter;
//    static bool isDead;
//    static bool needCallback;

//    static void atexitCallback() {
// #ifdef ATEXIT_FIXED
//         needCallback = true;
// #else
//         needCallback = false;
// #endif
//         GracefulDelete();
//     }
// };

// template <class T>
// atexit_pfn_t DeletableSingleton<T>::deleter = 0;

// template <class T>
// bool DeletableSingleton<T>::isDead = true;

// template <class T>
// bool DeletableSingleton<T>::needCallback = true;

// namespace Private
// {
//     template <class T>
//     struct Adapter
//     {
//         void operator()(T*) { return pFun_(); }
//         atexit_pfn_t pFun_;
//     };
// }

// template <class T>
// class SingletonWithLongevity
// {
//   public:
//     static void ScheduleDestruction(T* pObj, atexit_pfn_t pFun) {
//         Private::Adapter<T> adapter = { pFun };
//         SetLongevity(pObj, GetLongevity(pObj), adapter);
//     }

//     static void OnDeadReference() {
//         throw std::logic_error("Dead Reference Detected");
//     }
// };

// template <class T>
// struct NoDestroy
// {
//    static void ScheduleDestruction(T*, atexit_pfn_t)
//    {}

//    static void OnDeadReference()
//    {}
// };

// template <unsigned int Longevity, class T>
// class SingletonFixedLongevity
// {
//   public:
//     virtual ~SingletonFixedLongevity() {}

//     static void ScheduleDestruction(T* pObj, atexit_pfn_t pFun) {
//         Private::Adapter<T> adapter = { pFun };
//         SetLongevity(pObj, Longevity , adapter);
//     }

//     static void OnDeadReference() {
//         throw std::logic_error("Dead Reference Detected");
//    }
// };

// template <class T>
// struct DieLast : SingletonFixedLongevity<0xFFFFFFFF, T> {};

// template <class T>
// struct DieDirectlyBeforeLast : SingletonFixedLongevity<0xFFFFFFFF-1, T> {};

// template <class T>
// struct DieFirst : SingletonFixedLongevity<0,T> {};

// class FollowIntoDeath
// {
//     template<class T>
//     class Followers
//    {
//        typedef std::vector<atexit_pfn_t> Container;
//        typedef typename Container::iterator iterator;
//        static Container* followers_;

//    public:
//        static void Init() {
//            static bool done = false;
//            if(!done) {
//                followers_ = new Container;
//                done = true;
//            }
//        }

//        static void AddFollower(atexit_pfn_t ae) {
//            Init();
//            followers_->push_back(ae);
//        }

//        static void DestroyFollowers() {
//            Init();
//            for(iterator it = followers_->begin();it != followers_->end();++it){
//                (*it)();
//            }
//            delete followers_;
//        }
//    };

// public:
//     template<template <class> class Lifetime>
//     struct With
//     {
//         template<class Master>
//         struct AsMasterLifetime
//         {
//             static void ScheduleDestruction(Master* pObj, atexit_pfn_t pFun) {
//                 Followers<Master>::Init();
//                 Lifetime<Master>::ScheduleDestruction(pObj, pFun);

//                 Lifetime<Followers<Master> >::ScheduleDestruction(0, Followers<Master>::DestroyFollowers);
//             }

//             static void OnDeadReference()
//            {
//                throw std::logic_error("Dead Reference Detected");
//            }
//        };
//    };

//    template<class Master>
//    struct AfterMaster
//    {
//        template<class F>
//        struct IsDestroyed
//        {
//            static void ScheduleDestruction(F*, atexit_pfn_t pFun) {
//                Followers<Master>::AddFollower(pFun);
//            }

//            static void OnDeadReference() {
//                throw std::logic_error("Dead Reference Detected");
//            }
//        };
//    };
// };

// template<class T>
// typename FollowIntoDeath::Followers<T>::Container* FollowIntoDeath::Followers<T>::followers_ = 0;



// template
// <
//     class T,
//     template<class> class CreationPolicy = CreateUsingNew,
//     template<class> class LifetimePolicy = DefaultLifetime,
//     template<class> class ThreadingModel = SingleThreaded
// >
// class SingletonHolder
// {
//   public:
//     static T& Instance(){
//         if(!pInstance_){
//             typename ThreadingModel<T>::Lock guard;
//             if(!pInstance_){
//                 if(destroyed_){
//                     LifetimePolicy<T>::OnDeadReference();
//                     destroyed_ = false;
//                 }
//                 pInstance_ = CreationPolicy<T>::Create();
//                 LifetimePolicy<T>::ScheduleCall(&DestroySingleton(););
//             }
//         }
//         return pInstance_;
//    }

//  private:
//    SingletonHolder();
//    static void DestroySingleton(){
//        assert(!destroyed_);
//        CreationPolicy<T>::Destroy(pInstance_);
//        pInstance_ = 0;
//        destroyed_ = true;
//    }

//  private:
//    typedef ThreadingModel<T>::VolatileType InstanceType;

//    static InstanceType* pInstance_;
//    static bool destroyed_;
// };
}  // namespace xxcig

#endif  // SINGLETON_HPP
