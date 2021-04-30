# timercpp
Thread based timer

This fork uses a single thread per timer.
The timer mode can be PERIODIC or ONESHOT. This is a parameter passed to the constructor.

If the timer goes out of scope, it will stop and join the implementation thread.

```c++
Timer t ([&]() {
    cout << "Hey.. After each 1s..." << endl;
}, 1000ms, Mode::PERIODIC); 
```
### How to compile sample program?

```bash
g++ sample.cpp -std=c++14 -pthread
```

### License

[MIT](https://github.com/shalithasuranga/timercpp/edit/master/LICENSE)
