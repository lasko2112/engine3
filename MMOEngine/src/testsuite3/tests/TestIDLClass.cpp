/*
 *	testsuite3/tests/TestIDLClass.cpp generated by engine3 IDL compiler 0.60
 */

#include "TestIDLClass.h"

/*
 *	TestIDLClassStub
 */

enum {RPC_GETVALUE__ = 6,RPC_SETVALUE__INT_};

TestIDLClass::TestIDLClass(int val) : ManagedObject(DummyConstructorParameter::instance()) {
	TestIDLClassImplementation* _implementation = new TestIDLClassImplementation(val);
	_impl = _implementation;
	_impl->_setStub(this);
	_setClassName("TestIDLClass");
}

TestIDLClass::TestIDLClass(DummyConstructorParameter* param) : ManagedObject(param) {
	_setClassName("TestIDLClass");
}

TestIDLClass::~TestIDLClass() {
}



int TestIDLClass::getValue() {
	TestIDLClassImplementation* _implementation = static_cast<TestIDLClassImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_GETVALUE__);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getValue();
}

void TestIDLClass::setValue(int val) {
	TestIDLClassImplementation* _implementation = static_cast<TestIDLClassImplementation*>(_getImplementation());
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, RPC_SETVALUE__INT_);
		method.addSignedIntParameter(val);

		method.executeWithVoidReturn();
	} else
		_implementation->setValue(val);
}

DistributedObjectServant* TestIDLClass::_getImplementation() {

	_updated = true;
	return _impl;
}

void TestIDLClass::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;
}

/*
 *	TestIDLClassImplementation
 */

TestIDLClassImplementation::TestIDLClassImplementation(DummyConstructorParameter* param) : ManagedObjectImplementation(param) {
	_initializeImplementation();
}


TestIDLClassImplementation::~TestIDLClassImplementation() {
}


void TestIDLClassImplementation::finalize() {
}

void TestIDLClassImplementation::_initializeImplementation() {
	_setClassHelper(TestIDLClassHelper::instance());

	_this = NULL;

	_serializationHelperMethod();
}

void TestIDLClassImplementation::_setStub(DistributedObjectStub* stub) {
	_this = static_cast<TestIDLClass*>(stub);
	ManagedObjectImplementation::_setStub(stub);
}

DistributedObjectStub* TestIDLClassImplementation::_getStub() {
	return _this.get();
}

TestIDLClassImplementation::operator const TestIDLClass*() {
	return _this.get();
}

void TestIDLClassImplementation::lock(bool doLock) {
	_this.get()->lock(doLock);
}

void TestIDLClassImplementation::lock(ManagedObject* obj) {
	_this.get()->lock(obj);
}

void TestIDLClassImplementation::rlock(bool doLock) {
	_this.get()->rlock(doLock);
}

void TestIDLClassImplementation::wlock(bool doLock) {
	_this.get()->wlock(doLock);
}

void TestIDLClassImplementation::wlock(ManagedObject* obj) {
	_this.get()->wlock(obj);
}

void TestIDLClassImplementation::unlock(bool doLock) {
	_this.get()->unlock(doLock);
}

void TestIDLClassImplementation::runlock(bool doLock) {
	_this.get()->runlock(doLock);
}

void TestIDLClassImplementation::_serializationHelperMethod() {
	ManagedObjectImplementation::_serializationHelperMethod();

	_setClassName("TestIDLClass");

}

void TestIDLClassImplementation::readObject(ObjectInputStream* stream) {
	uint16 _varCount = stream->readShort();
	for (int i = 0; i < _varCount; ++i) {
		String _name;
		_name.parseFromBinaryStream(stream);

		uint32 _varSize = stream->readInt();

		int _currentOffset = stream->getOffset();

		if(TestIDLClassImplementation::readObjectMember(stream, _name)) {
		}

		stream->setOffset(_currentOffset + _varSize);
	}

	initializeTransientMembers();
}

bool TestIDLClassImplementation::readObjectMember(ObjectInputStream* stream, const String& _name) {
	if (ManagedObjectImplementation::readObjectMember(stream, _name))
		return true;

	if (_name == "TestIDLClass.value") {
		TypeInfo<int >::parseFromBinaryStream(&value, stream);
		return true;
	}


	return false;
}

void TestIDLClassImplementation::writeObject(ObjectOutputStream* stream) {
	int _currentOffset = stream->getOffset();
	stream->writeShort(0);
	int _varCount = TestIDLClassImplementation::writeObjectMembers(stream);
	stream->writeShort(_currentOffset, _varCount);
}

int TestIDLClassImplementation::writeObjectMembers(ObjectOutputStream* stream) {
	int _count = ManagedObjectImplementation::writeObjectMembers(stream);

	String _name;
	int _offset;
	uint32 _totalSize;
	_name = "TestIDLClass.value";
	_name.toBinaryStream(stream);
	_offset = stream->getOffset();
	stream->writeInt(0);
	TypeInfo<int >::toBinaryStream(&value, stream);
	_totalSize = (uint32) (stream->getOffset() - (_offset + 4));
	stream->writeInt(_offset, _totalSize);


	return _count + 1;
}

TestIDLClassImplementation::TestIDLClassImplementation(int val) {
	_initializeImplementation();
	// testsuite3/tests/TestIDLClass.idl():  		value = val;
	value = val;
}

int TestIDLClassImplementation::getValue() {
	// testsuite3/tests/TestIDLClass.idl():  		return value;
	return value;
}

void TestIDLClassImplementation::setValue(int val) {
	// testsuite3/tests/TestIDLClass.idl():  		value = val;
	value = val;
}

/*
 *	TestIDLClassAdapter
 */


#include "engine/orb/messages/InvokeMethodMessage.h"


TestIDLClassAdapter::TestIDLClassAdapter(TestIDLClass* obj) : ManagedObjectAdapter(obj) {
}

void TestIDLClassAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	DOBMessage* resp = inv->getInvocationMessage();

	switch (methid) {
	case RPC_GETVALUE__:
		{
			resp->insertSignedInt(getValue());
		}
		break;
	case RPC_SETVALUE__INT_:
		{
			setValue(inv->getSignedIntParameter());
		}
		break;
	default:
		throw Exception("Method does not exists");
	}
}

int TestIDLClassAdapter::getValue() {
	return (static_cast<TestIDLClass*>(stub))->getValue();
}

void TestIDLClassAdapter::setValue(int val) {
	(static_cast<TestIDLClass*>(stub))->setValue(val);
}

/*
 *	TestIDLClassHelper
 */

TestIDLClassHelper* TestIDLClassHelper::staticInitializer = TestIDLClassHelper::instance();

TestIDLClassHelper::TestIDLClassHelper() {
	className = "TestIDLClass";

	Core::getObjectBroker()->registerClass(className, this);
}

void TestIDLClassHelper::finalizeHelper() {
	TestIDLClassHelper::finalize();
}

DistributedObject* TestIDLClassHelper::instantiateObject() {
	return new TestIDLClass(DummyConstructorParameter::instance());
}

DistributedObjectServant* TestIDLClassHelper::instantiateServant() {
	return new TestIDLClassImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* TestIDLClassHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new TestIDLClassAdapter(static_cast<TestIDLClass*>(obj));

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}
