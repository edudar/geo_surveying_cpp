#include "angle_v8.hpp"

AngleV8::AngleV8(int degree, int minutes, double seconds) : Angle(degree, minutes, seconds) {}
AngleV8::AngleV8(Angle angle) : Angle(angle) {}

v8::Local<v8::Object> AngleV8::to_v8(v8::Isolate* isolate) {
    v8::Local<v8::Object> obj = v8::Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "degree"), v8::Number::New(isolate, get_degree()));
    obj->Set(v8::String::NewFromUtf8(isolate, "minutes"), v8::Number::New(isolate, get_minutes()));
    obj->Set(v8::String::NewFromUtf8(isolate, "seconds"), v8::Number::New(isolate, get_seconds()));
    return obj;
}

AngleV8 AngleV8::from_v8(v8::Isolate* isolate, v8::Handle<v8::Object> angle_obj) {
    v8::Handle<v8::Value> d = angle_obj->Get(v8::String::NewFromUtf8(isolate, "degree"));
    v8::Handle<v8::Value> m = angle_obj->Get(v8::String::NewFromUtf8(isolate, "minutes"));
    v8::Handle<v8::Value> s = angle_obj->Get(v8::String::NewFromUtf8(isolate, "seconds"));
    return AngleV8(d->NumberValue(), m->NumberValue(), s->NumberValue());
}
