// Copyright (c) 2011 The LevelDB Authors. All rights reserved.
// Use of this source code is governed by a BSD-style license that can be
// found in the LICENSE file. See the AUTHORS file for names of contributors.
//
// Log format information shared by reader and writer.
// See ../doc/log_format.md for more detail.

#ifndef STORAGE_LEVELDB_DB_LOG_FORMAT_H_
#define STORAGE_LEVELDB_DB_LOG_FORMAT_H_

namespace leveldb {
namespace log {
/**
 * 采用定长块的好处是可以方便的跳过有问题的块，防止日志文件出现损毁时能方便的跳过
 */
enum RecordType {   // WAL日志结构
  // Zero is reserved for preallocated files
  kZeroType = 0,

  kFullType = 1,    // 这是一个完整的 user record

  // For fragments
  kFirstType = 2,   // 这是 user record 的第一个 record
  kMiddleType = 3,  // 这是 user record 中间的 record, 如果写入的数据比较大，kMiddleType 的 record 可能有多个
  kLastType = 4     // 这是 user record 的最后一个 record
};
static const int kMaxRecordType = kLastType;

static const int kBlockSize = 32768;    // total size

// Header is checksum (4 bytes), length (2 bytes), type (1 byte).
static const int kHeaderSize = 4 + 2 + 1;

}  // namespace log
}  // namespace leveldb

#endif  // STORAGE_LEVELDB_DB_LOG_FORMAT_H_
