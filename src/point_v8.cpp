#include "point_v8.hpp"

PointV8::PointV8(double x, double y) : Point(x, y) {}

v8::Local<v8::Object> PointV8::to_v8(v8::Isolate* isolate) {
    v8::Local<v8::Object> obj = v8::Object::New(isolate);
    obj->Set(v8::String::NewFromUtf8(isolate, "x"), v8::Number::New(isolate, get_x()));
    obj->Set(v8::String::NewFromUtf8(isolate, "y"), v8::Number::New(isolate, get_y()));
    return obj;
}

PointV8 PointV8::from_v8(v8::Isolate* isolate, v8::Handle<v8::Object> point_obj) {
    v8::Handle<v8::Value> x = point_obj->Get(v8::String::NewFromUtf8(isolate, "x"));
    v8::Handle<v8::Value> y = point_obj->Get(v8::String::NewFromUtf8(isolate, "y"));
    return PointV8(x->NumberValue(), y->NumberValue());
}
