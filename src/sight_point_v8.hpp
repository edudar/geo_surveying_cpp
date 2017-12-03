#ifndef sight_point_v8_hpp
#define sight_point_v8_hpp

#include <node.h>
#include <node_object_wrap.h>

#include "sight_point.hpp"

class SightPointV8 : public SightPoint {
    
public:
    SightPointV8();
    SightPointV8(SightPointV8* cp);
    explicit SightPointV8(SightHeight backsight, double backsight_distance, SightHeight foresight,
                          double foresight_distance, bool output = false);
    SightPointV8(SightPoint sightPoint);
    
    v8::Local<v8::Object> to_v8(v8::Isolate* isolate);
    static SightPointV8 from_v8(v8::Isolate* isolate, v8::Handle<v8::Object> sight_point_obj);
    
};


#endif /* sight_point_v8_hpp */
