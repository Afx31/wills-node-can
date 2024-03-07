{
  "targets": [
    {
      "target_name": "testAddon",
      "sources": ["cpp/test/test.cpp"],
      "include_dirs": ["node_modules/nan"]
    },
    {
      "target_name": "WillsNodeCAN",
      "sources": ["cpp/can/can.cpp"],
      # "include_dirs": ["node_modules/nan"]
      "include_dirs": [
        "<!@(node -p \"require('nan')\")"
      ],
      "libraries": [ "-lpthread" ]
    }
  ]
}
