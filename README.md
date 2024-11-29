# assert-approx

浮動小数点数の演算精度誤差に対応するアサート機能。
有効ビット数を指定することで任意の精度でアサーションできる。

## example


```c
#ifndef DIGITS
#define DIGITS 10
#endif
#include "assert-approx/assert-approx.h"

int main() {
  assert_approx(0.3, 0.1 + 0.2);
  return 0;
}
```

`DIGITS`で有効ビット数を指定。  
デフォルトでは16bitとなる。

## 動作

引数の値が不一致であった場合は、場所と値を表示して関数が終了することなくエラー終了する。  
一致した場合は、0を返す。
