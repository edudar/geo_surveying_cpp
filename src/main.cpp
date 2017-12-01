#include <iostream>
#include <vector>

#include <node.h>
#include <v8.h>

#include "point.hpp"
#include "point_v8.hpp"
#include "angle.hpp"
#include "angle_v8.hpp"
#include "horizontal_point.hpp"
#include "horizontal_point_v8.hpp"
#include "traversing.hpp"
#include "three_wire_levelling.hpp"

template<typename T, typename... Args> std::unique_ptr<T> make_unique(Args&&... args) {
    return std::unique_ptr<T>(new T(std::forward<Args>(args)...));
}

void traverse_js(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();

  v8::Handle<v8::Object> point_obj = v8::Handle<v8::Object>::Cast(args[0]);
  auto point = PointV8::from_v8(isolate, point_obj);

  v8::Handle<v8::Object> azimuth_obj = v8::Handle<v8::Object>::Cast(args[1]);
  auto azimuth = AngleV8::from_v8(isolate, azimuth_obj);

  v8::Local<v8::Array> horizontal_points_obj = v8::Local<v8::Array>::Cast(args[2]);
  std::vector<std::unique_ptr<HorizontalPoint>> horizontal_points;
  int num_points = horizontal_points_obj->Length();
  for (int i = 0; i < num_points; i++) {
      horizontal_points.push_back(make_unique<HorizontalPointV8>(HorizontalPointV8::from_v8(isolate, v8::Local<v8::Object>::Cast(horizontal_points_obj->Get(i)))));
  }

  Traverser traversing = Traverser();
  TraversingSolution solution = traversing.solve(point, azimuth, horizontal_points);
  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, solution.to_string().c_str()));
}

//void three_wire_levelling_js(const v8::FunctionCallbackInfo<v8::Value>& args) {
//  v8::Isolate* isolate = args.GetIsolate();
//  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, three_wire_levelling().c_str()));
//}

void get_point_js(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  PointV8 p = PointV8(4.0, 5.0);
  args.GetReturnValue().Set(p.to_v8(isolate));
}

void get_point_str_js(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  PointV8 p = PointV8(4.0, 5.0);
  args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, p.to_string().c_str()));
}

void get_point_back_js(const v8::FunctionCallbackInfo<v8::Value>& args) {
  v8::Isolate* isolate = args.GetIsolate();
  v8::Handle<v8::Object> point_obj = v8::Handle<v8::Object>::Cast(args[0]);
  PointV8 p = PointV8::from_v8(isolate, point_obj);
  args.GetReturnValue().Set(p.to_v8(isolate));
}

void init(v8::Local<v8::Object> exports) {
  NODE_SET_METHOD(exports, "traverse", traverse_js);
//  NODE_SET_METHOD(exports, "three_wire_levelling", three_wire_levelling_js);
  NODE_SET_METHOD(exports, "get_point", get_point_js);
  NODE_SET_METHOD(exports, "get_point_str", get_point_str_js);
  NODE_SET_METHOD(exports, "get_point_back", get_point_back_js);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)
