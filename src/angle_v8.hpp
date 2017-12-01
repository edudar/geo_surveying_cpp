#ifndef angle_v8_hpp
#define angle_v8_hpp

#include <stdio.h>

#include <node.h>
#include <node_object_wrap.h>

#include "angle.hpp"

class AngleV8 : public Angle {
    
public:
    explicit AngleV8(int degree = 0, int minutes = 0, double seconds = 0);
    AngleV8(Angle angle);
    
    v8::Local<v8::Object> to_v8(v8::Isolate* isolate);
    static AngleV8 from_v8(v8::Isolate* isolate, v8::Handle<v8::Object> angle_obj);
    
};

#endif /* angle_v8_hpp */
