/*

    StackAlloc.hpp
    chickchirick-game-engine

    Created by <chickchirik> on 03/10/2019.

    DESCRIPTION:
    StackAlloc is a singleton stack memory allocator.

*/

#pragma once
#include <cstdint>

#define CAST(type, expr) reinterpret_cast<type>(expr)

class StackAlloc {
private:
    char*       pool;                                   /*  ptr to begining of the pool                             */
    uint32_t    marker    = 0;                          /*  shows the top of stack                                  */
    uint32_t    LSRSize   = 0;                          /*  size of Load&StayResident data                          */
    uint32_t    LSRMarker = 0;                          /*  marker to top of LSR data                               */
    uint32_t    realSize  = 0;                          /*  size of LSR + size of pool                              */
    StackAlloc();
public:
    static StackAlloc& getInstance();
    int startUP(uint32_t LSRSize_, uint32_t poolSize_); /*  start up routine                                        */
    int shutDown();                                     /*  shut down routine                                       */
    void* stalloc(uint32_t size);                       /*  allocate size bytes on stack                            */
    void* LSRalloc(uint32_t size);                      /*  allocate size bytes on LSR stack                        */
};
