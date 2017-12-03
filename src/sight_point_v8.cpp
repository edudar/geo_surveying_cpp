#include "sight_height_v8.hpp"
#include "sight_point.hpp"
#include "sight_point_v8.hpp"

SightPointV8::SightPointV8() : SightPoint() {}

SightPointV8::SightPointV8(SightPointV8* cp) : SightPoint(cp) {}

SightPointV8::SightPointV8(SightHeight backsight, double backsight_distance, SightHeight foresight,
                           double foresight_distance, bool output) : SightPoint(backsight, backsight_distance, foresight, foresight_distance, output) {}
SightPointV8::SightPointV8(SightPoint sightPoint) : SightPoint(sightPoint) {}

v8::Local<v8::Object> SightPointV8::to_v8(v8::Isolate* isolate) {
    v8::Local<v8::Object> sight_height_obj = v8::Object::New(isolate);
    sight_height_obj->Set(v8::String::NewFromUtf8(isolate, "backsight"),
                          SightHeightV8(get_backsight()).to_v8(isolate));
    sight_height_obj->Set(v8::String::NewFromUtf8(isolate, "backsightDistance"),
                          v8::Number::New(isolate, get_backsight_distance()));
    sight_height_obj->Set(v8::String::NewFromUtf8(isolate, "foresight"),
                          SightHeightV8(get_foresight()).to_v8(isolate));
    sight_height_obj->Set(v8::String::NewFromUtf8(isolate, "foresight"),
                          v8::Number::New(isolate, get_foresight_distance()));
    sight_height_obj->Set(v8::String::NewFromUtf8(isolate, "foresight"),
                          v8::Boolean::New(isolate, is_output()));
    return sight_height_obj;
}

SightPointV8 SightPointV8::from_v8(v8::Isolate* isolate, v8::Handle<v8::Object> sight_point_obj) {
    v8::Handle<v8::Object> bs =
        v8::Handle<v8::Object>::Cast(sight_point_obj->Get(v8::String::NewFromUtf8(isolate, "backsight")));
    v8::Handle<v8::Value> bs_d = sight_point_obj->Get(v8::String::NewFromUtf8(isolate, "backsightDistance"));
    v8::Handle<v8::Object> fs =
        v8::Handle<v8::Object>::Cast(sight_point_obj->Get(v8::String::NewFromUtf8(isolate, "foresight")));
    v8::Handle<v8::Value> fs_d = sight_point_obj->Get(v8::String::NewFromUtf8(isolate, "foresightDistance"));
    v8::Handle<v8::Value> o = sight_point_obj->Get(v8::String::NewFromUtf8(isolate, "output"));
    return SightPointV8(SightHeightV8::from_v8(isolate, bs), bs_d->NumberValue(),
                        SightHeightV8::from_v8(isolate, fs), fs_d->NumberValue(), o->BooleanValue());
}
