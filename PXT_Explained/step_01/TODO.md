# Showing an Expression and its Value

## Model Solution

When initially learning C++ it is often useful to writes
little demo programs to evaluate some expressions and show
their value.

## Practical Exercise

We are now going to show how tiny demo programs may quickly
develop into "little monsters" and how you can avoid this
with a systematic approach when it comes to "look at" the
value of an expression or the content of a variable.

> An alterative approach to "interactively" learn C++ would
  be to install [cling] and use its [REPL] mode.

[cling]: https://cdn.rawgit.com/root-project/cling/master/www/index.html
[REPL]: https://en.wikipedia.org/wiki/Read%E2%80%93eval%E2%80%93print_loop

### Take that piece of code …

… as an example how things may start innocuously: 

```
int a = 42;
std::cout << "initial value of `a` is " << a << std::endl;
a /= 7;
std::cout << "dividing by 7 makes `a` " << a << std::endl;
std::cout << "and prefix `++` yields " << ++a << std::endl;
std::cout << "so `a` ends up with value " << a << std::endl;
```

It looks like someone is trying out a few basic arithmetic
C++ operators to develop an understanding what they do.

Feel free to *Copy&Paste* the above fragment over into the
body of the current `main` program and RUN it.

### Writing less "prose"

Always being that "chatty" can quickly become a boring
nuisance.  If you extend that kind of program, if you need
a lot of text in the output statements you will probably
start to do a lot *Copy&Paste*. Then there is a tendency
you do inconsistent changes.

The below is obviously a bit contrived but shows the problem
that `a` is now divided by 6 (not 7) and the increment is
changed to postfix `++` but the output text is not adapted
accordingly:

```
int a = 42;
std::cout << "initial value of `a` is " << a << std::endl;
a /= 6;
std::cout << "dividing by 7 makes `a` " << a << std::endl;
std::cout << "and prefix `++` yields " << a++ << std::endl;
std::cout << "so `a` ends up with value " << a << std::endl;
```

It's probably not necessary to copy over the fragment
in the `main` program and RUN it to understand it is wrong.
(At least that its output is strongly misleading wrt. what
is actually demonstrated.)

### Writing less "prose"

```
int a = 42;
std::cout << a << std::endl;
std::cout << (a /= 6) << std::endl;
std::cout << a++ << std::endl;
```

Replace the body of `main` in the current program by the
above and check the output.

### But now it's a little bit too scarce

Surely you get all the right numbers now, but comparing
them to the expectations you had, when the wrote the demo
program, is harder now to see whether they are met.

And that's the point, last and finally: such little demo
programs allow to develop an understanding for C++ and see
how the source code relates to the generated output:
* If you supply lots of text explaining what has happened
  so far is more work and may get "out of sync" with the
  executed statements.
* But if without that additional information it becomes
  much harder to "explain" the output and relate it to
  the statements executed so far.

### It's always good to be lazy

Now comes the technique wit which you can to avoid repetitive
code. But you NEED the help of the C++-Preprocessor.

First copy this into the second line of the current program:

```
#define PX(expr) ((void)(std::cout << #expr "\t-> " << (expr) << std::endl))
```

**Pay attention that it stays ONE SINGLE LINE.**

(Using *Copy&Paste* instead re-typing it will probably get
it right. If not, widen your display window so that there is
no line wrapping any longer.)

Then change the main part of the program to this:

```
int a = 42;
PX(a);
PX(a /= 7);
PX(++a);
```

RUN and check the output.

Then RUN it again after making these modifications:
* `PX(a /= 7);` to `PX(a /= 6);` and
* `PX(++a);` to `PX(a++);`

The result should make it finally clear: We need to change
nothing else but the statements we want to try and the
output adapts accordingly.

### Now we're getting somewhere

We can put any expression in the round parentheses
after `PX` and as output see both,
* what the expression was and
* to what it evaluates.

### We'll use it a lot in the next days

Try to get accustomed to that lazy style generating control
output. And we'll not only use it a lot, we will also
substantially improve it. Just wait and see.
