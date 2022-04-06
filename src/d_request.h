// Node.js 15.11.0+: DeserializeRequest refactor

#ifndef D_REQUEST_H
#define D_REQUEST_H

#include "env.h"
#include "v8.h"
#include "node_snapshotable.h"

// DeserializeRequestCallback cb;
typedef void (*DeserializeRequestCallback)(v8::Local<v8::Context> context,
	v8::Local<v8::Object> holder,
	int index,
	node::InternalFieldInfo* info);

struct DeserializeRequest {
	DeserializeRequestCallback cb;
	v8::Global<v8::Object> holder;
	int index;
	node::InternalFieldInfo* info = nullptr;  // Owned by the request

	// Move constructor
	// DeserializeRequest(DeserializeRequest&& other) = default;
};

// struct DeserializeRequest(DeserializeRequestCallback, v8::Global<v8::Object>, int, InternalFieldInfo*);

#endif /* D_REQUEST_H */
