# __Programming with Go__

#### __Advantage of GO__:
* Code run fast
* Garbage collection
* Simpler object
* __Concurrency__ in Go

#### __Workspace__:
* bin - store all the executable
* package - library related to the workspace
* src - all the source code

#### __Go Tool__:
* __Go build__ - compiles the program and create executable for the main package
* __Go doc__ - prints documentation for a package
* __Go fmt__ - format the source code
* __Go get__ - download package and install them
* __Go list__ - list all installed packages
* __Go run__ - compile .go file and run executable
* __GO test__ - run tests using files ending in "_test.go"

#### __Keywords__:
* __import__ - access other packages

#### __Package__:
* __fmt__ - for format
  fmt.Printf(string1 + string2)
  fmt.Scan(&applenum)
* - for unicode
* - for string

#### __Code snippet__:
* __Varible Declaration and Definition__:
  __var__ x __int__
  __var__ x , y __*int__
  __var__ x __int__ = 100
  __var__ x = 100

* __Type alias__:
  __type__ Celsius __float64_

* __short varible Declaration__:
  x__:=__10
  ptr__:=__new(int) 
  const x = 1.8
  const ( x = 4
          z = "HI"
        )
* __iota__ - const set of value
  __type__ Grades int
  __const__ (
            A Grades = iota
            B
            C
            )

* __Control Flow__:
  * __if__ <condn>  {
      <consequent>
    }
 * __for__ <init>; <cond>;
   <update> {
      <stmts>
   }
 * __switch__ x {     __switch__ {
  __case__ 1:         __case__ x __>__ -1:
  __case__ 2:         __case__ x __<__ -1:
  __default__:        __default__ : 
  }                   )

* __Function Declaration__:
  __func(arg1, arg2)<return type>__:

#### __DATA STRUCTURE__:
* __ARRAY__:
  * __var__ arr __[3]int__ = [3]{1,2,3}
  * x := [...] int {1,2,3,5}
  * __for__ i, v __range__ x {
    }
* __SLICE__:
  * a := arr[1:3]
  * sli := __int[]__ {1,3,4}
  * __len__(a) , __cap__(a)
* __

