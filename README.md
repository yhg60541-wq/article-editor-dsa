# 基于线性表的文章编辑系统

一个用链表（线性表）实现的文本 / 文章编辑器，并配套一个 C# Windows 图形界面。编辑器以“行”为单位管理文章：可从文件读入文章、按行插入 / 删除 / 修改、统计字符与行数等，是“链表”数据结构的综合应用。

## 目录结构

- `linked-list-editor.cpp`：核心编辑器（链表实现，C++）
- `editor-variant.cpp`：另一版实现
- `visual studio_project/`：Visual Studio 工程（`.sln` / `.vcxproj`）
- `vs-ui/`：C# 图形界面（`.cs` / `.sln`）
- `Project1/` `Project2/`：相关子工程
- `article.txt`：示例文章

## 构建与运行

- 推荐在 **Windows + Visual Studio** 中打开 `.sln` 直接编译运行（核心代码用到了 `windows.h`，建议使用 MSVC）。
- 也可将 `linked-list-editor.cpp` 用支持 Windows 的 C++ 编译器单独编译。

## 功能

打开文件 → 按行管理文本 → 插入 / 删除 / 修改行 → 统计信息（行数、字符数等）。
