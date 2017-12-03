#include "sight_height_v8.hpp"

SightHeightV8::SightHeightV8(double upper, double middle, double lower) : SightHeight(upper, middle, lower) {}
SightHeightV8::SightHeightV8(SightHeight sightHeight) : SightHeight(sightHeight) {}

v8::Local<v8::Object> SightHeightV8::to_v8(v8::Isolate* isolate) {
    v8::Local<v8::Object> sight_height_obj = v8::Object::New(isolate);
    sight_height_obj->Set(v8::String::NewFromUtf8(isolate, "upper"), v8::Number::New(isolate, get_upper()));
    sight_height_obj->Set(v8::String::NewFromUtf8(isolate, "middle"), v8::Number::New(isolate, get_middle()));
    sight_height_obj->Set(v8::String::NewFromUtf8(isolate, "lower"), v8::Number::New(isolate, get_lower()));
    return sight_height_obj;
}

SightHeightV8 SightHeightV8::from_v8(v8::Isolate* isolate, v8::Handle<v8::Object> sight_height_obj) {
    v8::Handle<v8::Value> u = sight_height_obj->Get(v8::String::NewFromUtf8(isolate, "upper"));
    v8::Handle<v8::Value> m = sight_height_obj->Get(v8::String::NewFromUtf8(isolate, "middle"));
    v8::Handle<v8::Value> l = sight_height_obj->Get(v8::String::NewFromUtf8(isolate, "lower"));
    return SightHeightV8(u->NumberValue(), m->NumberValue(), l->NumberValue());
}
