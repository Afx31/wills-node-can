const addon = require('./build/Release/addon');

console.log('Hello:', addon.Hello());
console.log('HeresANumber:', addon.HeresANumber());
console.log('AddTenToThisNumber(5):', addon.AddTenToThisNumber(5));