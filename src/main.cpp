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
#include "sight_point.hpp"
#include "sight_point_v8.hpp"
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

void three_wire_leveling_js(const v8::FunctionCallbackInfo<v8::Value>& args) {
    v8::Isolate* isolate = args.GetIsolate();

    v8::Handle<v8::Value> benchmark_obj = v8::Handle<v8::Value>::Cast(args[0]);
    auto benchmark = benchmark_obj->NumberValue();
    
    v8::Local<v8::Array> sight_points_obj = v8::Local<v8::Array>::Cast(args[1]);
    std::vector<std::unique_ptr<SightPoint>> sight_points;
    int num_points = sight_points_obj->Length();
    for (int i = 0; i < num_points; i++) {
        sight_points.push_back(make_unique<SightPointV8>(SightPointV8::from_v8(isolate, v8::Local<v8::Object>::Cast(sight_points_obj->Get(i)))));
    }

    ThreeWireLevelling threeWireLevelling = ThreeWireLevelling();
    ThreeWireLevellingSolution solution = threeWireLevelling.solve(benchmark, sight_points);

    args.GetReturnValue().Set(v8::String::NewFromUtf8(isolate, solution.to_string().c_str()));
}

void init(v8::Local<v8::Object> exports) {
    NODE_SET_METHOD(exports, "traverse", traverse_js);
    NODE_SET_METHOD(exports, "three_wire_leveling", three_wire_leveling_js);
}

NODE_MODULE(NODE_GYP_MODULE_NAME, init)
