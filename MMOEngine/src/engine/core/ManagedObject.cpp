/*
 *	engine/core/ManagedObject.cpp generated by engine3 IDL compiler 0.60
 */

#include "ManagedObject.h"

/*
 *	ManagedObjectStub
 */

ManagedObject::ManagedObject(DummyConstructorParameter* param) {
	_impl = NULL;
}

ManagedObject::~ManagedObject() {
}

void ManagedObject::_lock(bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((ManagedObjectImplementation*) _impl)->lock(doLock);
}

void ManagedObject::_lock(ManagedObject* obj) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((ManagedObjectImplementation*) _impl)->lock(obj);
}

void ManagedObject::_wlock(bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((ManagedObjectImplementation*) _impl)->wlock(doLock);
}

void ManagedObject::_wlock(ManagedObject* obj) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addObjectParameter(obj);

		method.executeWithVoidReturn();
	} else
		((ManagedObjectImplementation*) _impl)->wlock(obj);
}

void ManagedObject::_unlock(bool doLock) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addBooleanParameter(doLock);

		method.executeWithVoidReturn();
	} else
		((ManagedObjectImplementation*) _impl)->unlock(doLock);
}

void ManagedObject::_setLockName(const String& name) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);
		method.addAsciiParameter(name);

		method.executeWithVoidReturn();
	} else
		((ManagedObjectImplementation*) _impl)->setLockName(name);
}

void ManagedObject::serialize(String& data) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 12);
		method.addAsciiParameter(data);

		method.executeWithVoidReturn();
	} else
		((ManagedObjectImplementation*) _impl)->serialize(data);
}

void ManagedObject::serialize(ObjectOutputStream* stream) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ManagedObjectImplementation*) _impl)->serialize(stream);
}

void ManagedObject::deSerialize(const String& data) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 13);
		method.addAsciiParameter(data);

		method.executeWithVoidReturn();
	} else
		((ManagedObjectImplementation*) _impl)->deSerialize(data);
}

void ManagedObject::deSerialize(ObjectInputStream* stream) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ManagedObjectImplementation*) _impl)->deSerialize(stream);
}

/*
 *	ManagedObjectImplementation
 */

ManagedObjectImplementation::ManagedObjectImplementation() {
	_classHelper = ManagedObjectHelper::instance();
}

ManagedObjectImplementation::~ManagedObjectImplementation() {
}

void ManagedObjectImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (ManagedObject*) stub;
}

DistributedObjectStub* ManagedObjectImplementation::_getStub() {
	return _this;
}

ManagedObjectImplementation::operator const ManagedObject*() {
	return _this;
}

void ManagedObjectImplementation::_serializationHelperMethod() {
}

void ManagedObjectImplementation::serialize(String& data) {
	// engine/core/ManagedObject.idl(32):  Serializable.serialize(data);
	Serializable::serialize(data);
}

void ManagedObjectImplementation::serialize(ObjectOutputStream* stream) {
	// engine/core/ManagedObject.idl(36):  Serializable.serialize(stream);
	Serializable::serialize(stream);
}

void ManagedObjectImplementation::deSerialize(const String& data) {
	// engine/core/ManagedObject.idl(40):  Serializable.deSerialize(data);
	Serializable::deSerialize(data);
}

void ManagedObjectImplementation::deSerialize(ObjectInputStream* stream) {
	// engine/core/ManagedObject.idl(44):  Serializable.deSerialize(stream);
	Serializable::deSerialize(stream);
}

/*
 *	ManagedObjectAdapter
 */

ManagedObjectAdapter::ManagedObjectAdapter(ManagedObjectImplementation* obj) : DistributedObjectAdapter((DistributedObjectServant*) obj) {
}

Packet* ManagedObjectAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		lock(inv->getBooleanParameter());
		break;
	case 7:
		lock((ManagedObject*) inv->getObjectParameter());
		break;
	case 8:
		wlock(inv->getBooleanParameter());
		break;
	case 9:
		wlock((ManagedObject*) inv->getObjectParameter());
		break;
	case 10:
		unlock(inv->getBooleanParameter());
		break;
	case 11:
		setLockName(inv->getAsciiParameter(_param0_setLockName__String_));
		break;
	case 12:
		serialize(inv->getAsciiParameter(_param0_serialize__String_));
		break;
	case 13:
		deSerialize(inv->getAsciiParameter(_param0_deSerialize__String_));
		break;
	default:
		return NULL;
	}

	return resp;
}

void ManagedObjectAdapter::lock(bool doLock) {
	return ((ManagedObjectImplementation*) impl)->lock(doLock);
}

void ManagedObjectAdapter::lock(ManagedObject* obj) {
	return ((ManagedObjectImplementation*) impl)->lock(obj);
}

void ManagedObjectAdapter::wlock(bool doLock) {
	return ((ManagedObjectImplementation*) impl)->wlock(doLock);
}

void ManagedObjectAdapter::wlock(ManagedObject* obj) {
	return ((ManagedObjectImplementation*) impl)->wlock(obj);
}

void ManagedObjectAdapter::unlock(bool doLock) {
	return ((ManagedObjectImplementation*) impl)->unlock(doLock);
}

void ManagedObjectAdapter::setLockName(const String& name) {
	return ((ManagedObjectImplementation*) impl)->setLockName(name);
}

void ManagedObjectAdapter::serialize(String& data) {
	return ((ManagedObjectImplementation*) impl)->serialize(data);
}

void ManagedObjectAdapter::deSerialize(const String& data) {
	return ((ManagedObjectImplementation*) impl)->deSerialize(data);
}

/*
 *	ManagedObjectHelper
 */

ManagedObjectHelper* ManagedObjectHelper::staticInitializer = ManagedObjectHelper::instance();

ManagedObjectHelper::ManagedObjectHelper() {
	className = "ManagedObject";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ManagedObjectHelper::finalizeHelper() {
	ManagedObjectHelper::finalize();
}

DistributedObject* ManagedObjectHelper::instantiateObject() {
	return new ManagedObject(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ManagedObjectHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ManagedObjectAdapter((ManagedObjectImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

