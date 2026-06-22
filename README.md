# Veridia

跨平台媒体库与播放器应用。后端使用 C++，前端按平台接入原生或跨平台实现；当前优先搭建 Apple 平台 SwiftUI 前端。

## 构建

```bash
cmake -S . -B build -DVERIDIA_PLATFORM=auto
cmake --build build
cmake --install build --prefix dist
```

`VERIDIA_PLATFORM=auto` 会在 Apple 平台选择 SwiftUI 前端。也可以显式指定：

```bash
cmake -S . -B build -DVERIDIA_PLATFORM=apple
```

如果只需要构建 C++ 后端和 C API 绑定层：

```bash
cmake -S . -B build-core -DVERIDIA_BUILD_FRONTEND=OFF
cmake --build build-core
```
