{
  "targets": [
    {
      "target_name": "addon",
      "cflags": [
        "-std=c++14",
        "-stdlib=libc++"
      ],
      "xcode_settings": {
        "OTHER_CFLAGS": [
          "-std=c++14",
          "-stdlib=libc++"
        ],
      },
      "sources": [
        "src/angle.hpp",
        "src/angle.cpp",
        "src/horizontal_point.hpp",
        "src/horizontal_point.cpp",
        "src/point.hpp",
        "src/point.cpp",
        "src/angle_v8.hpp",
        "src/angle_v8.cpp",
        "src/horizontal_point_v8.hpp",
        "src/horizontal_point_v8.cpp",
        "src/point_v8.hpp",
        "src/point_v8.cpp",
        "src/printer.hpp",
        "src/printer.cpp",
        "src/sight_height.hpp",
        "src/sight_height.cpp",
        "src/sight_point.hpp",
        "src/sight_point.cpp",
        "src/three_wire_levelling_solution.hpp",
        "src/three_wire_levelling_solution.cpp",
        "src/three_wire_levelling.hpp",
        "src/three_wire_levelling.cpp",
        "src/traversing_solution.hpp",
        "src/traversing_solution.cpp",
        "src/traversing.hpp",
        "src/traversing.cpp",
        "src/main.cpp"
      ]
    }
  ]
}
