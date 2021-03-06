//
// Generated file, do not edit! Created by nedtool 4.6 from core/message-files/dataMsg.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#include <iostream>
#include <sstream>
#include "dataMsg_m.h"

USING_NAMESPACE


// Another default rule (prevents compiler from choosing base class' doPacking())
template<typename T>
void doPacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doPacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}

template<typename T>
void doUnpacking(cCommBuffer *, T& t) {
    throw cRuntimeError("Parsim error: no doUnpacking() function for type %s or its base class (check .msg and _m.cc/h files!)",opp_typename(typeid(t)));
}




// Template rule for outputting std::vector<T> types
template<typename T, typename A>
inline std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec)
{
    out.put('{');
    for(typename std::vector<T,A>::const_iterator it = vec.begin(); it != vec.end(); ++it)
    {
        if (it != vec.begin()) {
            out.put(','); out.put(' ');
        }
        out << *it;
    }
    out.put('}');
    
    char buf[32];
    sprintf(buf, " (size=%u)", (unsigned int)vec.size());
    out.write(buf, strlen(buf));
    return out;
}

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

EXECUTE_ON_STARTUP(
    cEnum *e = cEnum::find("dataType");
    if (!e) enums.getInstance()->add(e = new cEnum("dataType"));
    e->insert(RTS, "RTS");
    e->insert(CTS, "CTS");
    e->insert(ACK, "ACK");
    e->insert(RTSNACK, "RTSNACK");
    e->insert(DATA, "DATA");
    e->insert(DATAACK, "DATAACK");
    e->insert(DATANACK, "DATANACK");
    e->insert(EOT, "EOT");
    e->insert(PUSTART, "PUSTART");
    e->insert(PUEND, "PUEND");
    e->insert(DRMCH, "DRMCH");
    e->insert(MACDATA, "MACDATA");
    e->insert(MACACK, "MACACK");
    e->insert(MOBILITY, "MOBILITY");
    e->insert(PUDATA, "PUDATA");
);

Register_Class(dataMsg);

dataMsg::dataMsg(const char *name, int kind) : ::cPacket(name,kind)
{
    this->kind_var = 0;
    this->numberOfPackets_var = 0;
    this->proposedChannel_var = 0;
    this->source_var = 0;
    this->destination_var = 0;
}

dataMsg::dataMsg(const dataMsg& other) : ::cPacket(other)
{
    copy(other);
}

dataMsg::~dataMsg()
{
}

dataMsg& dataMsg::operator=(const dataMsg& other)
{
    if (this==&other) return *this;
    ::cPacket::operator=(other);
    copy(other);
    return *this;
}

void dataMsg::copy(const dataMsg& other)
{
    this->kind_var = other.kind_var;
    this->numberOfPackets_var = other.numberOfPackets_var;
    this->proposedChannel_var = other.proposedChannel_var;
    this->source_var = other.source_var;
    this->destination_var = other.destination_var;
}

void dataMsg::parsimPack(cCommBuffer *b)
{
    ::cPacket::parsimPack(b);
    doPacking(b,this->kind_var);
    doPacking(b,this->numberOfPackets_var);
    doPacking(b,this->proposedChannel_var);
    doPacking(b,this->source_var);
    doPacking(b,this->destination_var);
}

void dataMsg::parsimUnpack(cCommBuffer *b)
{
    ::cPacket::parsimUnpack(b);
    doUnpacking(b,this->kind_var);
    doUnpacking(b,this->numberOfPackets_var);
    doUnpacking(b,this->proposedChannel_var);
    doUnpacking(b,this->source_var);
    doUnpacking(b,this->destination_var);
}

int dataMsg::getKind() const
{
    return kind_var;
}

void dataMsg::setKind(int kind)
{
    this->kind_var = kind;
}

int dataMsg::getNumberOfPackets() const
{
    return numberOfPackets_var;
}

void dataMsg::setNumberOfPackets(int numberOfPackets)
{
    this->numberOfPackets_var = numberOfPackets;
}

int dataMsg::getProposedChannel() const
{
    return proposedChannel_var;
}

void dataMsg::setProposedChannel(int proposedChannel)
{
    this->proposedChannel_var = proposedChannel;
}

int dataMsg::getSource() const
{
    return source_var;
}

void dataMsg::setSource(int source)
{
    this->source_var = source;
}

int dataMsg::getDestination() const
{
    return destination_var;
}

void dataMsg::setDestination(int destination)
{
    this->destination_var = destination;
}

class dataMsgDescriptor : public cClassDescriptor
{
  public:
    dataMsgDescriptor();
    virtual ~dataMsgDescriptor();

    virtual bool doesSupport(cObject *obj) const;
    virtual const char *getProperty(const char *propertyname) const;
    virtual int getFieldCount(void *object) const;
    virtual const char *getFieldName(void *object, int field) const;
    virtual int findField(void *object, const char *fieldName) const;
    virtual unsigned int getFieldTypeFlags(void *object, int field) const;
    virtual const char *getFieldTypeString(void *object, int field) const;
    virtual const char *getFieldProperty(void *object, int field, const char *propertyname) const;
    virtual int getArraySize(void *object, int field) const;

    virtual std::string getFieldAsString(void *object, int field, int i) const;
    virtual bool setFieldAsString(void *object, int field, int i, const char *value) const;

    virtual const char *getFieldStructName(void *object, int field) const;
    virtual void *getFieldStructPointer(void *object, int field, int i) const;
};

Register_ClassDescriptor(dataMsgDescriptor);

dataMsgDescriptor::dataMsgDescriptor() : cClassDescriptor("dataMsg", "cPacket")
{
}

dataMsgDescriptor::~dataMsgDescriptor()
{
}

bool dataMsgDescriptor::doesSupport(cObject *obj) const
{
    return dynamic_cast<dataMsg *>(obj)!=NULL;
}

const char *dataMsgDescriptor::getProperty(const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : NULL;
}

int dataMsgDescriptor::getFieldCount(void *object) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 5+basedesc->getFieldCount(object) : 5;
}

unsigned int dataMsgDescriptor::getFieldTypeFlags(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeFlags(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<5) ? fieldTypeFlags[field] : 0;
}

const char *dataMsgDescriptor::getFieldName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldNames[] = {
        "kind",
        "numberOfPackets",
        "proposedChannel",
        "source",
        "destination",
    };
    return (field>=0 && field<5) ? fieldNames[field] : NULL;
}

int dataMsgDescriptor::findField(void *object, const char *fieldName) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount(object) : 0;
    if (fieldName[0]=='k' && strcmp(fieldName, "kind")==0) return base+0;
    if (fieldName[0]=='n' && strcmp(fieldName, "numberOfPackets")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "proposedChannel")==0) return base+2;
    if (fieldName[0]=='s' && strcmp(fieldName, "source")==0) return base+3;
    if (fieldName[0]=='d' && strcmp(fieldName, "destination")==0) return base+4;
    return basedesc ? basedesc->findField(object, fieldName) : -1;
}

const char *dataMsgDescriptor::getFieldTypeString(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldTypeString(object, field);
        field -= basedesc->getFieldCount(object);
    }
    static const char *fieldTypeStrings[] = {
        "int",
        "int",
        "int",
        "int",
        "int",
    };
    return (field>=0 && field<5) ? fieldTypeStrings[field] : NULL;
}

const char *dataMsgDescriptor::getFieldProperty(void *object, int field, const char *propertyname) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldProperty(object, field, propertyname);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        case 0:
            if (!strcmp(propertyname,"enum")) return "dataType";
            return NULL;
        default: return NULL;
    }
}

int dataMsgDescriptor::getArraySize(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getArraySize(object, field);
        field -= basedesc->getFieldCount(object);
    }
    dataMsg *pp = (dataMsg *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

std::string dataMsgDescriptor::getFieldAsString(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldAsString(object,field,i);
        field -= basedesc->getFieldCount(object);
    }
    dataMsg *pp = (dataMsg *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getKind());
        case 1: return long2string(pp->getNumberOfPackets());
        case 2: return long2string(pp->getProposedChannel());
        case 3: return long2string(pp->getSource());
        case 4: return long2string(pp->getDestination());
        default: return "";
    }
}

bool dataMsgDescriptor::setFieldAsString(void *object, int field, int i, const char *value) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->setFieldAsString(object,field,i,value);
        field -= basedesc->getFieldCount(object);
    }
    dataMsg *pp = (dataMsg *)object; (void)pp;
    switch (field) {
        case 0: pp->setKind(string2long(value)); return true;
        case 1: pp->setNumberOfPackets(string2long(value)); return true;
        case 2: pp->setProposedChannel(string2long(value)); return true;
        case 3: pp->setSource(string2long(value)); return true;
        case 4: pp->setDestination(string2long(value)); return true;
        default: return false;
    }
}

const char *dataMsgDescriptor::getFieldStructName(void *object, int field) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructName(object, field);
        field -= basedesc->getFieldCount(object);
    }
    switch (field) {
        default: return NULL;
    };
}

void *dataMsgDescriptor::getFieldStructPointer(void *object, int field, int i) const
{
    cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount(object))
            return basedesc->getFieldStructPointer(object, field, i);
        field -= basedesc->getFieldCount(object);
    }
    dataMsg *pp = (dataMsg *)object; (void)pp;
    switch (field) {
        default: return NULL;
    }
}


