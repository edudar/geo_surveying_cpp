//
//  horizontal_point_v8.cpp
//  addon
//
//  Created by Eduard Dudar on 11/30/17.
//

#include "horizontal_point_v8.hpp"

HorizontalPointV8::HorizontalPointV8() : HorizontalPoint() {}

HorizontalPointV8::HorizontalPointV8(HorizontalPointV8* cp) : HorizontalPoint(cp) {}

HorizontalPointV8::HorizontalPointV8(AngleV8 left_angle, AngleV8 right_angle, double right_distance) : HorizontalPoint(left_angle, right_angle, right_distance) {}

v8::Local<v8::Object> HorizontalPointV8::to_v8(v8::Isolate* isolate) {
    v8::Local<v8::Object> obj = v8::Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "leftAngle"), AngleV8(get_left_angle()).to_v8(isolate));
    obj->Set(v8::String::NewFromUtf8(isolate, "rightAngle"), AngleV8(get_right_angle()).to_v8(isolate));
    obj->Set(v8::String::NewFromUtf8(isolate, "seconds"), v8::Number::New(isolate, get_right_distance()));
    return obj;
}

HorizontalPointV8* HorizontalPointV8::from_v8(v8::Isolate* isolate, v8::Handle<v8::Object> ha_obj) {
    v8::Handle<v8::Object> left_angle = v8::Handle<v8::Object>::Cast(ha_obj->Get(v8::String::NewFromUtf8(isolate, "leftAngle")));
    v8::Handle<v8::Object> right_angle = v8::Handle<v8::Object>::Cast(ha_obj->Get(v8::String::NewFromUtf8(isolate, "rightAngle")));
    v8::Handle<v8::Value> right_distance = ha_obj->Get(v8::String::NewFromUtf8(isolate, "rightDistance"));
    return new HorizontalPointV8(AngleV8::from_v8(isolate, left_angle), AngleV8::from_v8(isolate, right_angle), right_distance->NumberValue());
}
