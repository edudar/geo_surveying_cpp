const addon = require('bindings')('addon');
addon.traverse({
  x: 1000,
  y: 1000
}, {
  degree: 90,
  minutes: 0,
  seconds: 0
}, [
  {
    leftAngle: {
      degree: 314,
      minutes: 45,
      seconds: 44.15
    },
    rightAngle: {
      degree: 222,
      minutes: 42,
      seconds: 53.3
    },
    rightDistance: 83.103
  }, {
    leftAngle: {
      degree: 175,
      minutes: 20,
      seconds: 26.5
    },
    rightAngle: {
      degree: 92,
      minutes: 32,
      seconds: 30
    },
    rightDistance: 190.120
  }, {
    leftAngle: {
      degree: 321,
      minutes: 7,
      seconds: 24
    },
    rightAngle: {
      degree: 230,
      minutes: 18,
      seconds: 6
    },
    rightDistance: 53.115
  }, {
    leftAngle: {
      degree: 343,
      minutes: 29,
      seconds: 6.5
    },
    rightAngle: {
      degree: 243,
      minutes: 45,
      seconds: 43.5
    },
    rightDistance: 181.748
  }
]);
