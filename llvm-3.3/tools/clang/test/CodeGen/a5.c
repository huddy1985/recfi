// RUN: %clang -target armv7-none-linux-gnueabi -mcpu=cortex-a5 -emit-llvm -S %s  -o /dev/null

int main() {
  return 0;
}
