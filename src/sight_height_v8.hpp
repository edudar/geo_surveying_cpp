#ifndef sight_height_v8_hpp
#define sight_height_v8_hpp

#include <node.h>
#include <node_object_wrap.h>

#include "sight_point.hpp"

class SightHeightV8 : public SightHeight {
    
public:
    explicit SightHeightV8(double upper = 0.0, double middle = 0.0, double lower = 0.0);
    SightHeightV8(SightHeight sightHeight);
    
    v8::Local<v8::Object> to_v8(v8::Isolate* isolate);
    static SightHeightV8 from_v8(v8::Isolate* isolate, v8::Handle<v8::Object> sight_height_obj);
    
};

#endif /* sight_height_v8_hpp */
