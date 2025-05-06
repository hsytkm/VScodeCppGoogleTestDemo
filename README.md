# VScode GoogleTest

VSCode で Google Test を実行します。

Visual Studio での実行は こちら → [VCppGoogleTestDemo](https://github.com/hsytkm/VCppGoogleTestDemo)

2025/05/06 最新ツールでビルドを実行したので更新しました。

### 準備

以下を参考に対応しました。

[Google Test を使ってみる（その１：準備編） | 豆蔵デベロッパーサイト](https://developer.mamezou-tech.com/blogs/2022/11/04/google-test-01/)

[Google Test を使ってみる（その４：VSCode拡張機能編） | 豆蔵デベロッパーサイト](https://developer.mamezou-tech.com/blogs/2022/11/20/google-test-04/)

1. MinGW-w64 の入手

   [Releases · niXman/mingw-builds-binaries](https://github.com/niXman/mingw-builds-binaries/releases)

   `x86_64-15.1.0-release-posix-seh-ucrt-rt_v12-rev0.7z
`

2. CMake の入手

   [Download CMake](https://cmake.org/download/)

   `cmake-4.0.1-windows-x86_64.zip`

3. GoogleTest のビルド

   [Release · google/googletest](https://github.com/google/googletest/releases)

   `googletest-1.17.0.tar.gz`

    ```bash
    mkdir build
    cd build
    cmake .. -G "MinGW Makefiles"
    mingw32-make
    ```

4. GoogleTest の生成物をコピー

   lib / header ともに、ウェブページの指示通り `C:\dev\mingw64\` 以下でなく `C:\dev\mingw64\x86_64-w64-mingw32\` 以下にコピーします。（多分大事なはず）

   lib -> C:\dev\mingw64\x86_64-w64-mingw32\lib

   ```
   libgmock.a
   libgmock_main.a
   libgtest.a
   libgtest_main.a
   ```

   inlcude -> C:\dev\mingw64\x86_64-w64-mingw32\include

   ```
   \googletest\googletest\include\gtest
   \googletest\googlemock\include\gmock
   ```

5. VSCode の拡張機能 `GoogleTest Adapter` をインストールします。



### テストの実行

```sh
$ cd src
$ g++ add.c add_test.cpp -o test -g -pthread -lgtest_main -lgtest
$ ./test.exe
```

- `-g`: デバッグ情報を含んだ実行ファイルを生成するオプションです。デバッグ情報を含むことで、デバッグ時に変数名や行番号などの情報が使えるようになります。
- `-pthread` : マルチスレッドプログラミングに使用される pthread ライブラリをリンクします
- `-lgtest_main` : Google Test のメイン関数を提供するライブラリをリンクします。
- `-lgtest` : Google Test の本体のライブラリをリンクします。



### 参考元

[google/googletest: GoogleTest - Google Testing and Mocking Framework](https://github.com/google/googletest?tab=readme-ov-file)  GitHub Page

[GoogleTest User’s Guide | GoogleTest](https://google.github.io/googletest/)  GitHub.io

[Google Test — Google Test ドキュメント日本語訳](http://opencv.jp/googletestdocs/index.html)  日本語の解説ページ  v1.6.0(2011年)ベース



