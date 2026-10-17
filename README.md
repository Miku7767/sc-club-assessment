# 南昌大学超算俱乐部考核（C++ 方向）

姓名：周家名　|　学号：9110125032　|　进阶方向：C++

本仓库收录超算俱乐部基础阶段（Git / Linux）与进阶阶段（C++）的解题代码。

## 目录结构

```
sc-club-assessment/
├── README.md                        ← 本说明文件
├── 超算俱乐部考核报告.md              ← 技术报告 + 感悟报告（完整版）
├── 超算俱乐部考核报告.pdf             ← 报告 PDF 版
└── cpp/                             ← C++ 进阶阶段 5 道题
    ├── 01-basic-statistics/         ← 题目1：基础整数统计
    ├── 02-device-inspection/        ← 题目2：设备巡检记录统计
    ├── 03-ring-buffer/              ← 题目3：固定容量读数窗口（环形缓冲区）
    ├── 04-multifile-stats/          ← 题目4：多文件统计工具（CMake 构建）
    └── 05-parallel-quicksort/       ← 题目5：四线程并行快速排序
```

## 各题目说明

| 题目 | 内容 | 知识点 |
|------|------|--------|
| 01 基础整数统计 | 读 n 个整数，输出 count / sum / min / max | 输入输出、`long long` 防溢出 |
| 02 设备巡检记录统计 | 按类型统计四类设备记录数与总时长，输出最忙设备 | 结构体、`std::string`、if/else 分支 |
| 03 固定容量读数窗口 | 只保留最近 8 个读数，修复数组越界 | 环形缓冲区、`%` 取模、越界修复 |
| 04 多文件统计工具 | 修复 CMake 构建入口与函数声明/定义不一致 | CMake 多文件构建、C++ 重载、64 位求和 |
| 05 四线程快速排序 | 最多 4 个工作线程并行快排并验证有序 | `std::thread`、`std::atomic`、Lomuto 划分 |

## 编译方式

单文件题（01 / 02 / 03）：

```bash
g++ -std=c++17 -Wall -Wextra -o main main.cpp
```

多文件题（04，需 CMake ≥ 3.16）：

```bash
cmake -S . -B build
cmake --build build
./build/main < samples/01-wide.in
```

四线程题（05，需链接线程库）：

```bash
g++ -std=c++17 -pthread -o qsort qsort.cpp
```

## 基础阶段（Git / Linux）

基础阶段内容见报告中的「一、Git 部分」与「二、Linux 部分」，包括：

- Git：三层模型（工作区 / 暂存区 / 版本库）、`restore` / `reset` / `checkout`、分支与合并、commit 哈希
- Linux：`grep` / `mkdir` / `cp` / `printf` 等命令、`echo` 与 `printf` 区别、shell 重定向、bash 脚本参数处理
