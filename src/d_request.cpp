// Node.js 15.11.0+: DeserializeRequest refactor

#include "d_request.h"
#include "env.h"
#include "v8.h"
#include "bind.h"

struct DeserializeRequest(DeserializeRequestCallback cb,
	v8::Global<v8::Object> holder, int index, InternalFieldInfo* info) {
	&(this.cb) = base::Bind(&cb);
	this.holder = holder;
	this.index = index;
	this.info = info;
}

void Environment::EnqueueDeserializeRequest(DeserializeRequestCallback cb,
	Local<Object> holder,
	int index,
	InternalFieldInfo* info) {
	struct DeserializeRequest request { cb, { isolate(), holder }, index, info };
	deserialize_requests_.push_back(std::move(request));
}
