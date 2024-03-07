{
  "targets": [
    {
      "target_name": "WillsNodeCAN",
      "sources": ["cpp/can.cpp"],
      # "include_dirs": ["node_modules/nan"]
      "include_dirs": [
        "<!@(node -p \"require('nan')\")"
      ],
      "libraries": [ "-lpthread" ]
    }
  ]
}
