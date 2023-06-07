const addon = require('./build/Release/addon');

// Calling the 'hello' function from the C++ addon
console.log(addon.hello());
