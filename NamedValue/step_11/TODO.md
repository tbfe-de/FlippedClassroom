Show at least THREE different solutions by which a
`NamedValue` starts with the default (`value_`) of zero if
it's constructed by only giving the name.

-   for way(s) some you need an additional constructor ...
-   ... for others you don't.

I.e. the following should work and the contained value
should be 0:

```
NamedValue z("volume");
```

Actually there are four different ways (just saying ...)