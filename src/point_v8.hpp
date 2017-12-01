//
//  point_v8.hpp
//  addon
//
//  Created by Eduard Dudar on 11/30/17.
//

#ifndef point_v8_hpp
#define point_v8_hpp

#include <node.h>
#include <node_object_wrap.h>

#include "point.hpp"

class PointV8 : public Point {
    
public:
    explicit PointV8(double x = 0, double y = 0);
    
    v8::Local<v8::Object> to_v8(v8::Isolate* isolate);
    static PointV8 from_v8(v8::Isolate* isolate, v8::Handle<v8::Object> point_obj);

};

#endif /* point_v8_hpp */
