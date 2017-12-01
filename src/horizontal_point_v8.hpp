#ifndef horizontal_point_v8_hpp
#define horizontal_point_v8_hpp

#include "horizontal_point.hpp"
#include "angle_v8.hpp"

class HorizontalPointV8 : public HorizontalPoint {

public:
    HorizontalPointV8();
    HorizontalPointV8(HorizontalPointV8* cp);
    HorizontalPointV8(AngleV8 left_angle, AngleV8 right_angle, double right_distance);

    v8::Local<v8::Object> to_v8(v8::Isolate* isolate);
    static HorizontalPointV8* from_v8(v8::Isolate* isolate, v8::Handle<v8::Object> ha_obj);

};
#endif /* horizontal_point_v8_hpp */
