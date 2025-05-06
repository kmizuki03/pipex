# pipex

シェルのパイプ機能 `< file1 cmd1 | cmd2 > file2` をC言語で再現し、プロセスとファイルディスクリプタ操作を学びます。

## ✅ 構成

- 実行形式：`./pipex file1 cmd1 cmd2 file2`
- 挙動：`< file1 cmd1 | cmd2 > file2` と同等
- ファイル構成：`*.c`, `*.h`, `Makefile`
- 引数：
  - `file1`：入力ファイル
  - `cmd1`：最初のコマンド
  - `cmd2`：次のコマンド
  - `file2`：出力ファイル

## 🔧 使用可能関数

- `open`, `close`, `read`, `write`
- `malloc`, `free`, `perror`, `strerror`
- `access`, `dup`, `dup2`
- `execve`, `exit`, `fork`, `pipe`
- `unlink`, `wait`, `waitpid`
- `ft_printf（自作）`

## 💎 ボーナス（任意）

- 複数パイプ対応：`cmd1 | cmd2 | cmd3 ...`
- here_doc 対応：
  - `./pipex here_doc LIMITER cmd1 cmd2 file`
  - 挙動：`cmd << LIMITER | cmd2 >> file`

