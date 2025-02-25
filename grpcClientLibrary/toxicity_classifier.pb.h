// Generated by the protocol buffer compiler.  DO NOT EDIT!
// NO CHECKED-IN PROTOBUF GENCODE
// source: toxicity_classifier.proto
// Protobuf C++ Version: 5.27.2

#ifndef GOOGLE_PROTOBUF_INCLUDED_toxicity_5fclassifier_2eproto_2epb_2eh
#define GOOGLE_PROTOBUF_INCLUDED_toxicity_5fclassifier_2eproto_2epb_2eh

#include <limits>
#include <string>
#include <type_traits>
#include <utility>

#include "google/protobuf/runtime_version.h"
#if PROTOBUF_VERSION != 5027002
#error "Protobuf C++ gencode is built with an incompatible version of"
#error "Protobuf C++ headers/runtime. See"
#error "https://protobuf.dev/support/cross-version-runtime-guarantee/#cpp"
#endif
#include "google/protobuf/io/coded_stream.h"
#include "google/protobuf/arena.h"
#include "google/protobuf/arenastring.h"
#include "google/protobuf/generated_message_tctable_decl.h"
#include "google/protobuf/generated_message_util.h"
#include "google/protobuf/metadata_lite.h"
#include "google/protobuf/generated_message_reflection.h"
#include "google/protobuf/message.h"
#include "google/protobuf/repeated_field.h"  // IWYU pragma: export
#include "google/protobuf/extension_set.h"  // IWYU pragma: export
#include "google/protobuf/unknown_field_set.h"
// @@protoc_insertion_point(includes)

// Must be included last.
#include "google/protobuf/port_def.inc"

#define PROTOBUF_INTERNAL_EXPORT_toxicity_5fclassifier_2eproto

namespace google {
namespace protobuf {
namespace internal {
class AnyMetadata;
}  // namespace internal
}  // namespace protobuf
}  // namespace google

// Internal implementation detail -- do not use these members.
struct TableStruct_toxicity_5fclassifier_2eproto {
  static const ::uint32_t offsets[];
};
extern const ::google::protobuf::internal::DescriptorTable
    descriptor_table_toxicity_5fclassifier_2eproto;
namespace toxicity_classifier {
class MessageRequest;
struct MessageRequestDefaultTypeInternal;
extern MessageRequestDefaultTypeInternal _MessageRequest_default_instance_;
class MessageResponse;
struct MessageResponseDefaultTypeInternal;
extern MessageResponseDefaultTypeInternal _MessageResponse_default_instance_;
}  // namespace toxicity_classifier
namespace google {
namespace protobuf {
}  // namespace protobuf
}  // namespace google

namespace toxicity_classifier {

// ===================================================================


// -------------------------------------------------------------------

class MessageResponse final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:toxicity_classifier.MessageResponse) */ {
 public:
  inline MessageResponse() : MessageResponse(nullptr) {}
  ~MessageResponse() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR MessageResponse(
      ::google::protobuf::internal::ConstantInitialized);

  inline MessageResponse(const MessageResponse& from) : MessageResponse(nullptr, from) {}
  inline MessageResponse(MessageResponse&& from) noexcept
      : MessageResponse(nullptr, std::move(from)) {}
  inline MessageResponse& operator=(const MessageResponse& from) {
    CopyFrom(from);
    return *this;
  }
  inline MessageResponse& operator=(MessageResponse&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MessageResponse& default_instance() {
    return *internal_default_instance();
  }
  static inline const MessageResponse* internal_default_instance() {
    return reinterpret_cast<const MessageResponse*>(
        &_MessageResponse_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 1;
  friend void swap(MessageResponse& a, MessageResponse& b) { a.Swap(&b); }
  inline void Swap(MessageResponse* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MessageResponse* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MessageResponse* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<MessageResponse>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const MessageResponse& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const MessageResponse& from) { MessageResponse::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(MessageResponse* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "toxicity_classifier.MessageResponse"; }

 protected:
  explicit MessageResponse(::google::protobuf::Arena* arena);
  MessageResponse(::google::protobuf::Arena* arena, const MessageResponse& from);
  MessageResponse(::google::protobuf::Arena* arena, MessageResponse&& from) noexcept
      : MessageResponse(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kToxicityProbabilityFieldNumber = 1,
  };
  // float toxicity_probability = 1;
  void clear_toxicity_probability() ;
  float toxicity_probability() const;
  void set_toxicity_probability(float value);

  private:
  float _internal_toxicity_probability() const;
  void _internal_set_toxicity_probability(float value);

  public:
  // @@protoc_insertion_point(class_scope:toxicity_classifier.MessageResponse)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      0, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_MessageResponse_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const MessageResponse& from_msg);
    float toxicity_probability_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_toxicity_5fclassifier_2eproto;
};
// -------------------------------------------------------------------

class MessageRequest final : public ::google::protobuf::Message
/* @@protoc_insertion_point(class_definition:toxicity_classifier.MessageRequest) */ {
 public:
  inline MessageRequest() : MessageRequest(nullptr) {}
  ~MessageRequest() override;
  template <typename = void>
  explicit PROTOBUF_CONSTEXPR MessageRequest(
      ::google::protobuf::internal::ConstantInitialized);

  inline MessageRequest(const MessageRequest& from) : MessageRequest(nullptr, from) {}
  inline MessageRequest(MessageRequest&& from) noexcept
      : MessageRequest(nullptr, std::move(from)) {}
  inline MessageRequest& operator=(const MessageRequest& from) {
    CopyFrom(from);
    return *this;
  }
  inline MessageRequest& operator=(MessageRequest&& from) noexcept {
    if (this == &from) return *this;
    if (GetArena() == from.GetArena()
#ifdef PROTOBUF_FORCE_COPY_IN_MOVE
        && GetArena() != nullptr
#endif  // !PROTOBUF_FORCE_COPY_IN_MOVE
    ) {
      InternalSwap(&from);
    } else {
      CopyFrom(from);
    }
    return *this;
  }

  inline const ::google::protobuf::UnknownFieldSet& unknown_fields() const
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.unknown_fields<::google::protobuf::UnknownFieldSet>(::google::protobuf::UnknownFieldSet::default_instance);
  }
  inline ::google::protobuf::UnknownFieldSet* mutable_unknown_fields()
      ABSL_ATTRIBUTE_LIFETIME_BOUND {
    return _internal_metadata_.mutable_unknown_fields<::google::protobuf::UnknownFieldSet>();
  }

  static const ::google::protobuf::Descriptor* descriptor() {
    return GetDescriptor();
  }
  static const ::google::protobuf::Descriptor* GetDescriptor() {
    return default_instance().GetMetadata().descriptor;
  }
  static const ::google::protobuf::Reflection* GetReflection() {
    return default_instance().GetMetadata().reflection;
  }
  static const MessageRequest& default_instance() {
    return *internal_default_instance();
  }
  static inline const MessageRequest* internal_default_instance() {
    return reinterpret_cast<const MessageRequest*>(
        &_MessageRequest_default_instance_);
  }
  static constexpr int kIndexInFileMessages = 0;
  friend void swap(MessageRequest& a, MessageRequest& b) { a.Swap(&b); }
  inline void Swap(MessageRequest* other) {
    if (other == this) return;
#ifdef PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() != nullptr && GetArena() == other->GetArena()) {
#else   // PROTOBUF_FORCE_COPY_IN_SWAP
    if (GetArena() == other->GetArena()) {
#endif  // !PROTOBUF_FORCE_COPY_IN_SWAP
      InternalSwap(other);
    } else {
      ::google::protobuf::internal::GenericSwap(this, other);
    }
  }
  void UnsafeArenaSwap(MessageRequest* other) {
    if (other == this) return;
    ABSL_DCHECK(GetArena() == other->GetArena());
    InternalSwap(other);
  }

  // implements Message ----------------------------------------------

  MessageRequest* New(::google::protobuf::Arena* arena = nullptr) const final {
    return ::google::protobuf::Message::DefaultConstruct<MessageRequest>(arena);
  }
  using ::google::protobuf::Message::CopyFrom;
  void CopyFrom(const MessageRequest& from);
  using ::google::protobuf::Message::MergeFrom;
  void MergeFrom(const MessageRequest& from) { MessageRequest::MergeImpl(*this, from); }

  private:
  static void MergeImpl(
      ::google::protobuf::MessageLite& to_msg,
      const ::google::protobuf::MessageLite& from_msg);

  public:
  bool IsInitialized() const {
    return true;
  }
  ABSL_ATTRIBUTE_REINITIALIZES void Clear() final;
  ::size_t ByteSizeLong() const final;
  ::uint8_t* _InternalSerialize(
      ::uint8_t* target,
      ::google::protobuf::io::EpsCopyOutputStream* stream) const final;
  int GetCachedSize() const { return _impl_._cached_size_.Get(); }

  private:
  void SharedCtor(::google::protobuf::Arena* arena);
  void SharedDtor();
  void InternalSwap(MessageRequest* other);
 private:
  friend class ::google::protobuf::internal::AnyMetadata;
  static ::absl::string_view FullMessageName() { return "toxicity_classifier.MessageRequest"; }

 protected:
  explicit MessageRequest(::google::protobuf::Arena* arena);
  MessageRequest(::google::protobuf::Arena* arena, const MessageRequest& from);
  MessageRequest(::google::protobuf::Arena* arena, MessageRequest&& from) noexcept
      : MessageRequest(arena) {
    *this = ::std::move(from);
  }
  const ::google::protobuf::Message::ClassData* GetClassData() const final;

 public:
  ::google::protobuf::Metadata GetMetadata() const;
  // nested types ----------------------------------------------------

  // accessors -------------------------------------------------------
  enum : int {
    kMessageFieldNumber = 1,
  };
  // string message = 1;
  void clear_message() ;
  const std::string& message() const;
  template <typename Arg_ = const std::string&, typename... Args_>
  void set_message(Arg_&& arg, Args_... args);
  std::string* mutable_message();
  PROTOBUF_NODISCARD std::string* release_message();
  void set_allocated_message(std::string* value);

  private:
  const std::string& _internal_message() const;
  inline PROTOBUF_ALWAYS_INLINE void _internal_set_message(
      const std::string& value);
  std::string* _internal_mutable_message();

  public:
  // @@protoc_insertion_point(class_scope:toxicity_classifier.MessageRequest)
 private:
  class _Internal;
  friend class ::google::protobuf::internal::TcParser;
  static const ::google::protobuf::internal::TcParseTable<
      0, 1, 0,
      50, 2>
      _table_;

  static constexpr const void* _raw_default_instance_ =
      &_MessageRequest_default_instance_;

  friend class ::google::protobuf::MessageLite;
  friend class ::google::protobuf::Arena;
  template <typename T>
  friend class ::google::protobuf::Arena::InternalHelper;
  using InternalArenaConstructable_ = void;
  using DestructorSkippable_ = void;
  struct Impl_ {
    inline explicit constexpr Impl_(
        ::google::protobuf::internal::ConstantInitialized) noexcept;
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena);
    inline explicit Impl_(::google::protobuf::internal::InternalVisibility visibility,
                          ::google::protobuf::Arena* arena, const Impl_& from,
                          const MessageRequest& from_msg);
    ::google::protobuf::internal::ArenaStringPtr message_;
    mutable ::google::protobuf::internal::CachedSize _cached_size_;
    PROTOBUF_TSAN_DECLARE_MEMBER
  };
  union { Impl_ _impl_; };
  friend struct ::TableStruct_toxicity_5fclassifier_2eproto;
};

// ===================================================================




// ===================================================================


#ifdef __GNUC__
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"
#endif  // __GNUC__
// -------------------------------------------------------------------

// MessageRequest

// string message = 1;
inline void MessageRequest::clear_message() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.message_.ClearToEmpty();
}
inline const std::string& MessageRequest::message() const
    ABSL_ATTRIBUTE_LIFETIME_BOUND {
  // @@protoc_insertion_point(field_get:toxicity_classifier.MessageRequest.message)
  return _internal_message();
}
template <typename Arg_, typename... Args_>
inline PROTOBUF_ALWAYS_INLINE void MessageRequest::set_message(Arg_&& arg,
                                                     Args_... args) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.message_.Set(static_cast<Arg_&&>(arg), args..., GetArena());
  // @@protoc_insertion_point(field_set:toxicity_classifier.MessageRequest.message)
}
inline std::string* MessageRequest::mutable_message() ABSL_ATTRIBUTE_LIFETIME_BOUND {
  std::string* _s = _internal_mutable_message();
  // @@protoc_insertion_point(field_mutable:toxicity_classifier.MessageRequest.message)
  return _s;
}
inline const std::string& MessageRequest::_internal_message() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.message_.Get();
}
inline void MessageRequest::_internal_set_message(const std::string& value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.message_.Set(value, GetArena());
}
inline std::string* MessageRequest::_internal_mutable_message() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  return _impl_.message_.Mutable( GetArena());
}
inline std::string* MessageRequest::release_message() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  // @@protoc_insertion_point(field_release:toxicity_classifier.MessageRequest.message)
  return _impl_.message_.Release();
}
inline void MessageRequest::set_allocated_message(std::string* value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.message_.SetAllocated(value, GetArena());
  #ifdef PROTOBUF_FORCE_COPY_DEFAULT_STRING
        if (_impl_.message_.IsDefault()) {
          _impl_.message_.Set("", GetArena());
        }
  #endif  // PROTOBUF_FORCE_COPY_DEFAULT_STRING
  // @@protoc_insertion_point(field_set_allocated:toxicity_classifier.MessageRequest.message)
}

// -------------------------------------------------------------------

// MessageResponse

// float toxicity_probability = 1;
inline void MessageResponse::clear_toxicity_probability() {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.toxicity_probability_ = 0;
}
inline float MessageResponse::toxicity_probability() const {
  // @@protoc_insertion_point(field_get:toxicity_classifier.MessageResponse.toxicity_probability)
  return _internal_toxicity_probability();
}
inline void MessageResponse::set_toxicity_probability(float value) {
  _internal_set_toxicity_probability(value);
  // @@protoc_insertion_point(field_set:toxicity_classifier.MessageResponse.toxicity_probability)
}
inline float MessageResponse::_internal_toxicity_probability() const {
  ::google::protobuf::internal::TSanRead(&_impl_);
  return _impl_.toxicity_probability_;
}
inline void MessageResponse::_internal_set_toxicity_probability(float value) {
  ::google::protobuf::internal::TSanWrite(&_impl_);
  _impl_.toxicity_probability_ = value;
}

#ifdef __GNUC__
#pragma GCC diagnostic pop
#endif  // __GNUC__

// @@protoc_insertion_point(namespace_scope)
}  // namespace toxicity_classifier


// @@protoc_insertion_point(global_scope)

#include "google/protobuf/port_undef.inc"

#endif  // GOOGLE_PROTOBUF_INCLUDED_toxicity_5fclassifier_2eproto_2epb_2eh
