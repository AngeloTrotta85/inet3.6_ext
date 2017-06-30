//
// Generated file, do not edit! Created by nedtool 5.1 from inet/applications/base/ApplicationPacketExt.msg.
//

// Disable warnings about unused variables, empty switch stmts, etc:
#ifdef _MSC_VER
#  pragma warning(disable:4101)
#  pragma warning(disable:4065)
#endif

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wshadow"
#  pragma clang diagnostic ignored "-Wconversion"
#  pragma clang diagnostic ignored "-Wunused-parameter"
#  pragma clang diagnostic ignored "-Wc++98-compat"
#  pragma clang diagnostic ignored "-Wunreachable-code-break"
#  pragma clang diagnostic ignored "-Wold-style-cast"
#elif defined(__GNUC__)
#  pragma GCC diagnostic ignored "-Wshadow"
#  pragma GCC diagnostic ignored "-Wconversion"
#  pragma GCC diagnostic ignored "-Wunused-parameter"
#  pragma GCC diagnostic ignored "-Wold-style-cast"
#  pragma GCC diagnostic ignored "-Wsuggest-attribute=noreturn"
#  pragma GCC diagnostic ignored "-Wfloat-conversion"
#endif

#include <iostream>
#include <sstream>
#include "ApplicationPacketExt_m.h"

namespace omnetpp {

// Template pack/unpack rules. They are declared *after* a1l type-specific pack functions for multiple reasons.
// They are in the omnetpp namespace, to allow them to be found by argument-dependent lookup via the cCommBuffer argument

// Packing/unpacking an std::vector
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::vector<T,A>& v)
{
    int n = v.size();
    doParsimPacking(buffer, n);
    for (int i = 0; i < n; i++)
        doParsimPacking(buffer, v[i]);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::vector<T,A>& v)
{
    int n;
    doParsimUnpacking(buffer, n);
    v.resize(n);
    for (int i = 0; i < n; i++)
        doParsimUnpacking(buffer, v[i]);
}

// Packing/unpacking an std::list
template<typename T, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::list<T,A>& l)
{
    doParsimPacking(buffer, (int)l.size());
    for (typename std::list<T,A>::const_iterator it = l.begin(); it != l.end(); ++it)
        doParsimPacking(buffer, (T&)*it);
}

template<typename T, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::list<T,A>& l)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        l.push_back(T());
        doParsimUnpacking(buffer, l.back());
    }
}

// Packing/unpacking an std::set
template<typename T, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::set<T,Tr,A>& s)
{
    doParsimPacking(buffer, (int)s.size());
    for (typename std::set<T,Tr,A>::const_iterator it = s.begin(); it != s.end(); ++it)
        doParsimPacking(buffer, *it);
}

template<typename T, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::set<T,Tr,A>& s)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        T x;
        doParsimUnpacking(buffer, x);
        s.insert(x);
    }
}

// Packing/unpacking an std::map
template<typename K, typename V, typename Tr, typename A>
void doParsimPacking(omnetpp::cCommBuffer *buffer, const std::map<K,V,Tr,A>& m)
{
    doParsimPacking(buffer, (int)m.size());
    for (typename std::map<K,V,Tr,A>::const_iterator it = m.begin(); it != m.end(); ++it) {
        doParsimPacking(buffer, it->first);
        doParsimPacking(buffer, it->second);
    }
}

template<typename K, typename V, typename Tr, typename A>
void doParsimUnpacking(omnetpp::cCommBuffer *buffer, std::map<K,V,Tr,A>& m)
{
    int n;
    doParsimUnpacking(buffer, n);
    for (int i=0; i<n; i++) {
        K k; V v;
        doParsimUnpacking(buffer, k);
        doParsimUnpacking(buffer, v);
        m[k] = v;
    }
}

// Default pack/unpack function for arrays
template<typename T>
void doParsimArrayPacking(omnetpp::cCommBuffer *b, const T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimPacking(b, t[i]);
}

template<typename T>
void doParsimArrayUnpacking(omnetpp::cCommBuffer *b, T *t, int n)
{
    for (int i = 0; i < n; i++)
        doParsimUnpacking(b, t[i]);
}

// Default rule to prevent compiler from choosing base class' doParsimPacking() function
template<typename T>
void doParsimPacking(omnetpp::cCommBuffer *, const T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimPacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

template<typename T>
void doParsimUnpacking(omnetpp::cCommBuffer *, T& t)
{
    throw omnetpp::cRuntimeError("Parsim error: No doParsimUnpacking() function for type %s", omnetpp::opp_typename(typeid(t)));
}

}  // namespace omnetpp

namespace inet {

// forward
template<typename T, typename A>
std::ostream& operator<<(std::ostream& out, const std::vector<T,A>& vec);

// Template rule which fires if a struct or class doesn't have operator<<
template<typename T>
inline std::ostream& operator<<(std::ostream& out,const T&) {return out;}

// operator<< for std::vector<T>
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

nodeinfo::nodeinfo()
{
    this->appAddr = 0;
    this->velTheta = 0;
    this->meanVelThetaNeighbourood = 0;
    this->velThetaVariance = 0;
    this->velThetaMean = 0;
    this->meanVelThetaVarianceNeighbourood = 0;
    this->meanVelThetaMeanNeighbourood = 0;
    this->velLength = 0;
    this->meanVelLengthNeighbourood = 0;
    this->velLengthVariance = 0;
    this->velLengthMean = 0;
    this->meanVelLengthVarianceNeighbourood = 0;
    this->meanVelLengthMeanNeighbourood = 0;
    this->distance = 0;
    this->meanDistanceNeighbourood = 0;
    this->approaching = 0;
    this->meanApproachingNeighbourood = 0;
    this->nodeDegree = 0;
    this->meanNodeDegreeNeighbourood = 0;
    this->nodeDegreeVariance = 0;
    this->meanNodeDegreeVarianceNeighbourood = 0;
    this->meanSnrNeighbourood = 0;
    this->snrNeighbourood = 0;
    this->meanPowNeighbourood = 0;
    this->powNeighbourood = 0;
    this->meanPerNeighbourood = 0;
    this->perNeighbourood = 0;
    this->queueMacSizeAbs = 0;
    this->meanQueueMacSizeAbsNeighbourood = 0;
    this->queueMacSizePerc = 0;
    this->meanQueueMacSizePercNeighbourood = 0;
    this->l3Metric = 0;
    this->meanL3MetricNeighbourood = 0;
    this->througputMeanSecWindow = 0;
    this->througputVarSecWindow = 0;
    this->througputMeanNumWindow = 0;
    this->througputVarNumWindow = 0;
    this->meanThrougputMeanSecWindowNeighbourood = 0;
    this->meanThrougputVarSecWindowNeighbourood = 0;
    this->meanThrougputMeanNumWindowNeighbourood = 0;
    this->meanThrougputVarNumWindowNeighbourood = 0;
    this->througputMeanTrendSecWindow = 0;
    this->meanThrougputMeanTrendSecWindowNeighbourood = 0;
    this->delayMeanSecWindow = 0;
    this->delayVarSecWindow = 0;
    this->delayMeanNumWindow = 0;
    this->delayVarNumWindow = 0;
    this->meanDelayMeanSecWindowNeighbourood = 0;
    this->meanDelayVarSecWindowNeighbourood = 0;
    this->meanDelayMeanNumWindowNeighbourood = 0;
    this->meanDelayVarNumWindowNeighbourood = 0;
    this->delayMeanTrendSecWindow = 0;
    this->meanDelayMeanTrendSecWindowNeighbourood = 0;
    this->pdrSecWindow = 0;
    this->pdrNumWindow = 0;
    this->meanPdrSecWindowNeighbourood = 0;
    this->meanPdrNumWindowNeighbourood = 0;
    this->pdrTrendSecWindow = 0;
    this->meanPdrTrendSecWindowNeighbourood = 0;
    this->nextHopDistance = 0;
    this->meanNextHopDistanceNeighbourood = 0;
    this->nextHopApproaching = 0;
    this->meanNextHopApproachingNeighbourood = 0;
}

void __doPacking(omnetpp::cCommBuffer *b, const nodeinfo& a)
{
    doParsimPacking(b,a.localAddr);
    doParsimPacking(b,a.appAddr);
    doParsimPacking(b,a.pos);
    doParsimPacking(b,a.velocity);
    doParsimPacking(b,a.meanVelocityNeighbourood);
    doParsimPacking(b,a.velTheta);
    doParsimPacking(b,a.meanVelThetaNeighbourood);
    doParsimPacking(b,a.velThetaVariance);
    doParsimPacking(b,a.velThetaMean);
    doParsimPacking(b,a.meanVelThetaVarianceNeighbourood);
    doParsimPacking(b,a.meanVelThetaMeanNeighbourood);
    doParsimPacking(b,a.velLength);
    doParsimPacking(b,a.meanVelLengthNeighbourood);
    doParsimPacking(b,a.velLengthVariance);
    doParsimPacking(b,a.velLengthMean);
    doParsimPacking(b,a.meanVelLengthVarianceNeighbourood);
    doParsimPacking(b,a.meanVelLengthMeanNeighbourood);
    doParsimPacking(b,a.distance);
    doParsimPacking(b,a.meanDistanceNeighbourood);
    doParsimPacking(b,a.approaching);
    doParsimPacking(b,a.meanApproachingNeighbourood);
    doParsimPacking(b,a.nodeDegree);
    doParsimPacking(b,a.meanNodeDegreeNeighbourood);
    doParsimPacking(b,a.nodeDegreeVariance);
    doParsimPacking(b,a.meanNodeDegreeVarianceNeighbourood);
    doParsimPacking(b,a.meanSnrNeighbourood);
    doParsimPacking(b,a.snrNeighbourood);
    doParsimPacking(b,a.meanPowNeighbourood);
    doParsimPacking(b,a.powNeighbourood);
    doParsimPacking(b,a.meanPerNeighbourood);
    doParsimPacking(b,a.perNeighbourood);
    doParsimPacking(b,a.queueMacSizeAbs);
    doParsimPacking(b,a.meanQueueMacSizeAbsNeighbourood);
    doParsimPacking(b,a.queueMacSizePerc);
    doParsimPacking(b,a.meanQueueMacSizePercNeighbourood);
    doParsimPacking(b,a.l3Metric);
    doParsimPacking(b,a.meanL3MetricNeighbourood);
    doParsimPacking(b,a.througputMeanSecWindow);
    doParsimPacking(b,a.througputVarSecWindow);
    doParsimPacking(b,a.througputMeanNumWindow);
    doParsimPacking(b,a.througputVarNumWindow);
    doParsimPacking(b,a.meanThrougputMeanSecWindowNeighbourood);
    doParsimPacking(b,a.meanThrougputVarSecWindowNeighbourood);
    doParsimPacking(b,a.meanThrougputMeanNumWindowNeighbourood);
    doParsimPacking(b,a.meanThrougputVarNumWindowNeighbourood);
    doParsimPacking(b,a.througputMeanTrendSecWindow);
    doParsimPacking(b,a.meanThrougputMeanTrendSecWindowNeighbourood);
    doParsimPacking(b,a.delayMeanSecWindow);
    doParsimPacking(b,a.delayVarSecWindow);
    doParsimPacking(b,a.delayMeanNumWindow);
    doParsimPacking(b,a.delayVarNumWindow);
    doParsimPacking(b,a.meanDelayMeanSecWindowNeighbourood);
    doParsimPacking(b,a.meanDelayVarSecWindowNeighbourood);
    doParsimPacking(b,a.meanDelayMeanNumWindowNeighbourood);
    doParsimPacking(b,a.meanDelayVarNumWindowNeighbourood);
    doParsimPacking(b,a.delayMeanTrendSecWindow);
    doParsimPacking(b,a.meanDelayMeanTrendSecWindowNeighbourood);
    doParsimPacking(b,a.pdrSecWindow);
    doParsimPacking(b,a.pdrNumWindow);
    doParsimPacking(b,a.meanPdrSecWindowNeighbourood);
    doParsimPacking(b,a.meanPdrNumWindowNeighbourood);
    doParsimPacking(b,a.pdrTrendSecWindow);
    doParsimPacking(b,a.meanPdrTrendSecWindowNeighbourood);
    doParsimPacking(b,a.nextHopDistance);
    doParsimPacking(b,a.meanNextHopDistanceNeighbourood);
    doParsimPacking(b,a.nextHopApproaching);
    doParsimPacking(b,a.meanNextHopApproachingNeighbourood);
}

void __doUnpacking(omnetpp::cCommBuffer *b, nodeinfo& a)
{
    doParsimUnpacking(b,a.localAddr);
    doParsimUnpacking(b,a.appAddr);
    doParsimUnpacking(b,a.pos);
    doParsimUnpacking(b,a.velocity);
    doParsimUnpacking(b,a.meanVelocityNeighbourood);
    doParsimUnpacking(b,a.velTheta);
    doParsimUnpacking(b,a.meanVelThetaNeighbourood);
    doParsimUnpacking(b,a.velThetaVariance);
    doParsimUnpacking(b,a.velThetaMean);
    doParsimUnpacking(b,a.meanVelThetaVarianceNeighbourood);
    doParsimUnpacking(b,a.meanVelThetaMeanNeighbourood);
    doParsimUnpacking(b,a.velLength);
    doParsimUnpacking(b,a.meanVelLengthNeighbourood);
    doParsimUnpacking(b,a.velLengthVariance);
    doParsimUnpacking(b,a.velLengthMean);
    doParsimUnpacking(b,a.meanVelLengthVarianceNeighbourood);
    doParsimUnpacking(b,a.meanVelLengthMeanNeighbourood);
    doParsimUnpacking(b,a.distance);
    doParsimUnpacking(b,a.meanDistanceNeighbourood);
    doParsimUnpacking(b,a.approaching);
    doParsimUnpacking(b,a.meanApproachingNeighbourood);
    doParsimUnpacking(b,a.nodeDegree);
    doParsimUnpacking(b,a.meanNodeDegreeNeighbourood);
    doParsimUnpacking(b,a.nodeDegreeVariance);
    doParsimUnpacking(b,a.meanNodeDegreeVarianceNeighbourood);
    doParsimUnpacking(b,a.meanSnrNeighbourood);
    doParsimUnpacking(b,a.snrNeighbourood);
    doParsimUnpacking(b,a.meanPowNeighbourood);
    doParsimUnpacking(b,a.powNeighbourood);
    doParsimUnpacking(b,a.meanPerNeighbourood);
    doParsimUnpacking(b,a.perNeighbourood);
    doParsimUnpacking(b,a.queueMacSizeAbs);
    doParsimUnpacking(b,a.meanQueueMacSizeAbsNeighbourood);
    doParsimUnpacking(b,a.queueMacSizePerc);
    doParsimUnpacking(b,a.meanQueueMacSizePercNeighbourood);
    doParsimUnpacking(b,a.l3Metric);
    doParsimUnpacking(b,a.meanL3MetricNeighbourood);
    doParsimUnpacking(b,a.througputMeanSecWindow);
    doParsimUnpacking(b,a.througputVarSecWindow);
    doParsimUnpacking(b,a.througputMeanNumWindow);
    doParsimUnpacking(b,a.througputVarNumWindow);
    doParsimUnpacking(b,a.meanThrougputMeanSecWindowNeighbourood);
    doParsimUnpacking(b,a.meanThrougputVarSecWindowNeighbourood);
    doParsimUnpacking(b,a.meanThrougputMeanNumWindowNeighbourood);
    doParsimUnpacking(b,a.meanThrougputVarNumWindowNeighbourood);
    doParsimUnpacking(b,a.througputMeanTrendSecWindow);
    doParsimUnpacking(b,a.meanThrougputMeanTrendSecWindowNeighbourood);
    doParsimUnpacking(b,a.delayMeanSecWindow);
    doParsimUnpacking(b,a.delayVarSecWindow);
    doParsimUnpacking(b,a.delayMeanNumWindow);
    doParsimUnpacking(b,a.delayVarNumWindow);
    doParsimUnpacking(b,a.meanDelayMeanSecWindowNeighbourood);
    doParsimUnpacking(b,a.meanDelayVarSecWindowNeighbourood);
    doParsimUnpacking(b,a.meanDelayMeanNumWindowNeighbourood);
    doParsimUnpacking(b,a.meanDelayVarNumWindowNeighbourood);
    doParsimUnpacking(b,a.delayMeanTrendSecWindow);
    doParsimUnpacking(b,a.meanDelayMeanTrendSecWindowNeighbourood);
    doParsimUnpacking(b,a.pdrSecWindow);
    doParsimUnpacking(b,a.pdrNumWindow);
    doParsimUnpacking(b,a.meanPdrSecWindowNeighbourood);
    doParsimUnpacking(b,a.meanPdrNumWindowNeighbourood);
    doParsimUnpacking(b,a.pdrTrendSecWindow);
    doParsimUnpacking(b,a.meanPdrTrendSecWindowNeighbourood);
    doParsimUnpacking(b,a.nextHopDistance);
    doParsimUnpacking(b,a.meanNextHopDistanceNeighbourood);
    doParsimUnpacking(b,a.nextHopApproaching);
    doParsimUnpacking(b,a.meanNextHopApproachingNeighbourood);
}

class nodeinfoDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    nodeinfoDescriptor();
    virtual ~nodeinfoDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(nodeinfoDescriptor)

nodeinfoDescriptor::nodeinfoDescriptor() : omnetpp::cClassDescriptor("inet::nodeinfo", "")
{
    propertynames = nullptr;
}

nodeinfoDescriptor::~nodeinfoDescriptor()
{
    delete[] propertynames;
}

bool nodeinfoDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<nodeinfo *>(obj)!=nullptr;
}

const char **nodeinfoDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *nodeinfoDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int nodeinfoDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 67+basedesc->getFieldCount() : 67;
}

unsigned int nodeinfoDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
        FD_ISEDITABLE,
    };
    return (field>=0 && field<67) ? fieldTypeFlags[field] : 0;
}

const char *nodeinfoDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "localAddr",
        "appAddr",
        "pos",
        "velocity",
        "meanVelocityNeighbourood",
        "velTheta",
        "meanVelThetaNeighbourood",
        "velThetaVariance",
        "velThetaMean",
        "meanVelThetaVarianceNeighbourood",
        "meanVelThetaMeanNeighbourood",
        "velLength",
        "meanVelLengthNeighbourood",
        "velLengthVariance",
        "velLengthMean",
        "meanVelLengthVarianceNeighbourood",
        "meanVelLengthMeanNeighbourood",
        "distance",
        "meanDistanceNeighbourood",
        "approaching",
        "meanApproachingNeighbourood",
        "nodeDegree",
        "meanNodeDegreeNeighbourood",
        "nodeDegreeVariance",
        "meanNodeDegreeVarianceNeighbourood",
        "meanSnrNeighbourood",
        "snrNeighbourood",
        "meanPowNeighbourood",
        "powNeighbourood",
        "meanPerNeighbourood",
        "perNeighbourood",
        "queueMacSizeAbs",
        "meanQueueMacSizeAbsNeighbourood",
        "queueMacSizePerc",
        "meanQueueMacSizePercNeighbourood",
        "l3Metric",
        "meanL3MetricNeighbourood",
        "througputMeanSecWindow",
        "througputVarSecWindow",
        "througputMeanNumWindow",
        "througputVarNumWindow",
        "meanThrougputMeanSecWindowNeighbourood",
        "meanThrougputVarSecWindowNeighbourood",
        "meanThrougputMeanNumWindowNeighbourood",
        "meanThrougputVarNumWindowNeighbourood",
        "througputMeanTrendSecWindow",
        "meanThrougputMeanTrendSecWindowNeighbourood",
        "delayMeanSecWindow",
        "delayVarSecWindow",
        "delayMeanNumWindow",
        "delayVarNumWindow",
        "meanDelayMeanSecWindowNeighbourood",
        "meanDelayVarSecWindowNeighbourood",
        "meanDelayMeanNumWindowNeighbourood",
        "meanDelayVarNumWindowNeighbourood",
        "delayMeanTrendSecWindow",
        "meanDelayMeanTrendSecWindowNeighbourood",
        "pdrSecWindow",
        "pdrNumWindow",
        "meanPdrSecWindowNeighbourood",
        "meanPdrNumWindowNeighbourood",
        "pdrTrendSecWindow",
        "meanPdrTrendSecWindowNeighbourood",
        "nextHopDistance",
        "meanNextHopDistanceNeighbourood",
        "nextHopApproaching",
        "meanNextHopApproachingNeighbourood",
    };
    return (field>=0 && field<67) ? fieldNames[field] : nullptr;
}

int nodeinfoDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='l' && strcmp(fieldName, "localAddr")==0) return base+0;
    if (fieldName[0]=='a' && strcmp(fieldName, "appAddr")==0) return base+1;
    if (fieldName[0]=='p' && strcmp(fieldName, "pos")==0) return base+2;
    if (fieldName[0]=='v' && strcmp(fieldName, "velocity")==0) return base+3;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanVelocityNeighbourood")==0) return base+4;
    if (fieldName[0]=='v' && strcmp(fieldName, "velTheta")==0) return base+5;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanVelThetaNeighbourood")==0) return base+6;
    if (fieldName[0]=='v' && strcmp(fieldName, "velThetaVariance")==0) return base+7;
    if (fieldName[0]=='v' && strcmp(fieldName, "velThetaMean")==0) return base+8;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanVelThetaVarianceNeighbourood")==0) return base+9;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanVelThetaMeanNeighbourood")==0) return base+10;
    if (fieldName[0]=='v' && strcmp(fieldName, "velLength")==0) return base+11;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanVelLengthNeighbourood")==0) return base+12;
    if (fieldName[0]=='v' && strcmp(fieldName, "velLengthVariance")==0) return base+13;
    if (fieldName[0]=='v' && strcmp(fieldName, "velLengthMean")==0) return base+14;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanVelLengthVarianceNeighbourood")==0) return base+15;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanVelLengthMeanNeighbourood")==0) return base+16;
    if (fieldName[0]=='d' && strcmp(fieldName, "distance")==0) return base+17;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanDistanceNeighbourood")==0) return base+18;
    if (fieldName[0]=='a' && strcmp(fieldName, "approaching")==0) return base+19;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanApproachingNeighbourood")==0) return base+20;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodeDegree")==0) return base+21;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanNodeDegreeNeighbourood")==0) return base+22;
    if (fieldName[0]=='n' && strcmp(fieldName, "nodeDegreeVariance")==0) return base+23;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanNodeDegreeVarianceNeighbourood")==0) return base+24;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanSnrNeighbourood")==0) return base+25;
    if (fieldName[0]=='s' && strcmp(fieldName, "snrNeighbourood")==0) return base+26;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanPowNeighbourood")==0) return base+27;
    if (fieldName[0]=='p' && strcmp(fieldName, "powNeighbourood")==0) return base+28;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanPerNeighbourood")==0) return base+29;
    if (fieldName[0]=='p' && strcmp(fieldName, "perNeighbourood")==0) return base+30;
    if (fieldName[0]=='q' && strcmp(fieldName, "queueMacSizeAbs")==0) return base+31;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanQueueMacSizeAbsNeighbourood")==0) return base+32;
    if (fieldName[0]=='q' && strcmp(fieldName, "queueMacSizePerc")==0) return base+33;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanQueueMacSizePercNeighbourood")==0) return base+34;
    if (fieldName[0]=='l' && strcmp(fieldName, "l3Metric")==0) return base+35;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanL3MetricNeighbourood")==0) return base+36;
    if (fieldName[0]=='t' && strcmp(fieldName, "througputMeanSecWindow")==0) return base+37;
    if (fieldName[0]=='t' && strcmp(fieldName, "througputVarSecWindow")==0) return base+38;
    if (fieldName[0]=='t' && strcmp(fieldName, "througputMeanNumWindow")==0) return base+39;
    if (fieldName[0]=='t' && strcmp(fieldName, "througputVarNumWindow")==0) return base+40;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanThrougputMeanSecWindowNeighbourood")==0) return base+41;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanThrougputVarSecWindowNeighbourood")==0) return base+42;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanThrougputMeanNumWindowNeighbourood")==0) return base+43;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanThrougputVarNumWindowNeighbourood")==0) return base+44;
    if (fieldName[0]=='t' && strcmp(fieldName, "througputMeanTrendSecWindow")==0) return base+45;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanThrougputMeanTrendSecWindowNeighbourood")==0) return base+46;
    if (fieldName[0]=='d' && strcmp(fieldName, "delayMeanSecWindow")==0) return base+47;
    if (fieldName[0]=='d' && strcmp(fieldName, "delayVarSecWindow")==0) return base+48;
    if (fieldName[0]=='d' && strcmp(fieldName, "delayMeanNumWindow")==0) return base+49;
    if (fieldName[0]=='d' && strcmp(fieldName, "delayVarNumWindow")==0) return base+50;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanDelayMeanSecWindowNeighbourood")==0) return base+51;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanDelayVarSecWindowNeighbourood")==0) return base+52;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanDelayMeanNumWindowNeighbourood")==0) return base+53;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanDelayVarNumWindowNeighbourood")==0) return base+54;
    if (fieldName[0]=='d' && strcmp(fieldName, "delayMeanTrendSecWindow")==0) return base+55;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanDelayMeanTrendSecWindowNeighbourood")==0) return base+56;
    if (fieldName[0]=='p' && strcmp(fieldName, "pdrSecWindow")==0) return base+57;
    if (fieldName[0]=='p' && strcmp(fieldName, "pdrNumWindow")==0) return base+58;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanPdrSecWindowNeighbourood")==0) return base+59;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanPdrNumWindowNeighbourood")==0) return base+60;
    if (fieldName[0]=='p' && strcmp(fieldName, "pdrTrendSecWindow")==0) return base+61;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanPdrTrendSecWindowNeighbourood")==0) return base+62;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHopDistance")==0) return base+63;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanNextHopDistanceNeighbourood")==0) return base+64;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextHopApproaching")==0) return base+65;
    if (fieldName[0]=='m' && strcmp(fieldName, "meanNextHopApproachingNeighbourood")==0) return base+66;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *nodeinfoDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "L3Address",
        "int",
        "Coord",
        "Coord",
        "Coord",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "int",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
        "double",
    };
    return (field>=0 && field<67) ? fieldTypeStrings[field] : nullptr;
}

const char **nodeinfoDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *nodeinfoDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int nodeinfoDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    nodeinfo *pp = (nodeinfo *)object; (void)pp;
    switch (field) {
        default: return 0;
    }
}

const char *nodeinfoDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    nodeinfo *pp = (nodeinfo *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string nodeinfoDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    nodeinfo *pp = (nodeinfo *)object; (void)pp;
    switch (field) {
        case 0: {std::stringstream out; out << pp->localAddr; return out.str();}
        case 1: return long2string(pp->appAddr);
        case 2: {std::stringstream out; out << pp->pos; return out.str();}
        case 3: {std::stringstream out; out << pp->velocity; return out.str();}
        case 4: {std::stringstream out; out << pp->meanVelocityNeighbourood; return out.str();}
        case 5: return double2string(pp->velTheta);
        case 6: return double2string(pp->meanVelThetaNeighbourood);
        case 7: return double2string(pp->velThetaVariance);
        case 8: return double2string(pp->velThetaMean);
        case 9: return double2string(pp->meanVelThetaVarianceNeighbourood);
        case 10: return double2string(pp->meanVelThetaMeanNeighbourood);
        case 11: return double2string(pp->velLength);
        case 12: return double2string(pp->meanVelLengthNeighbourood);
        case 13: return double2string(pp->velLengthVariance);
        case 14: return double2string(pp->velLengthMean);
        case 15: return double2string(pp->meanVelLengthVarianceNeighbourood);
        case 16: return double2string(pp->meanVelLengthMeanNeighbourood);
        case 17: return double2string(pp->distance);
        case 18: return double2string(pp->meanDistanceNeighbourood);
        case 19: return double2string(pp->approaching);
        case 20: return double2string(pp->meanApproachingNeighbourood);
        case 21: return long2string(pp->nodeDegree);
        case 22: return double2string(pp->meanNodeDegreeNeighbourood);
        case 23: return double2string(pp->nodeDegreeVariance);
        case 24: return double2string(pp->meanNodeDegreeVarianceNeighbourood);
        case 25: return double2string(pp->meanSnrNeighbourood);
        case 26: return double2string(pp->snrNeighbourood);
        case 27: return double2string(pp->meanPowNeighbourood);
        case 28: return double2string(pp->powNeighbourood);
        case 29: return double2string(pp->meanPerNeighbourood);
        case 30: return double2string(pp->perNeighbourood);
        case 31: return double2string(pp->queueMacSizeAbs);
        case 32: return double2string(pp->meanQueueMacSizeAbsNeighbourood);
        case 33: return double2string(pp->queueMacSizePerc);
        case 34: return double2string(pp->meanQueueMacSizePercNeighbourood);
        case 35: return double2string(pp->l3Metric);
        case 36: return double2string(pp->meanL3MetricNeighbourood);
        case 37: return double2string(pp->througputMeanSecWindow);
        case 38: return double2string(pp->througputVarSecWindow);
        case 39: return double2string(pp->througputMeanNumWindow);
        case 40: return double2string(pp->througputVarNumWindow);
        case 41: return double2string(pp->meanThrougputMeanSecWindowNeighbourood);
        case 42: return double2string(pp->meanThrougputVarSecWindowNeighbourood);
        case 43: return double2string(pp->meanThrougputMeanNumWindowNeighbourood);
        case 44: return double2string(pp->meanThrougputVarNumWindowNeighbourood);
        case 45: return double2string(pp->througputMeanTrendSecWindow);
        case 46: return double2string(pp->meanThrougputMeanTrendSecWindowNeighbourood);
        case 47: return double2string(pp->delayMeanSecWindow);
        case 48: return double2string(pp->delayVarSecWindow);
        case 49: return double2string(pp->delayMeanNumWindow);
        case 50: return double2string(pp->delayVarNumWindow);
        case 51: return double2string(pp->meanDelayMeanSecWindowNeighbourood);
        case 52: return double2string(pp->meanDelayVarSecWindowNeighbourood);
        case 53: return double2string(pp->meanDelayMeanNumWindowNeighbourood);
        case 54: return double2string(pp->meanDelayVarNumWindowNeighbourood);
        case 55: return double2string(pp->delayMeanTrendSecWindow);
        case 56: return double2string(pp->meanDelayMeanTrendSecWindowNeighbourood);
        case 57: return double2string(pp->pdrSecWindow);
        case 58: return double2string(pp->pdrNumWindow);
        case 59: return double2string(pp->meanPdrSecWindowNeighbourood);
        case 60: return double2string(pp->meanPdrNumWindowNeighbourood);
        case 61: return double2string(pp->pdrTrendSecWindow);
        case 62: return double2string(pp->meanPdrTrendSecWindowNeighbourood);
        case 63: return double2string(pp->nextHopDistance);
        case 64: return double2string(pp->meanNextHopDistanceNeighbourood);
        case 65: return double2string(pp->nextHopApproaching);
        case 66: return double2string(pp->meanNextHopApproachingNeighbourood);
        default: return "";
    }
}

bool nodeinfoDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    nodeinfo *pp = (nodeinfo *)object; (void)pp;
    switch (field) {
        case 1: pp->appAddr = string2long(value); return true;
        case 5: pp->velTheta = string2double(value); return true;
        case 6: pp->meanVelThetaNeighbourood = string2double(value); return true;
        case 7: pp->velThetaVariance = string2double(value); return true;
        case 8: pp->velThetaMean = string2double(value); return true;
        case 9: pp->meanVelThetaVarianceNeighbourood = string2double(value); return true;
        case 10: pp->meanVelThetaMeanNeighbourood = string2double(value); return true;
        case 11: pp->velLength = string2double(value); return true;
        case 12: pp->meanVelLengthNeighbourood = string2double(value); return true;
        case 13: pp->velLengthVariance = string2double(value); return true;
        case 14: pp->velLengthMean = string2double(value); return true;
        case 15: pp->meanVelLengthVarianceNeighbourood = string2double(value); return true;
        case 16: pp->meanVelLengthMeanNeighbourood = string2double(value); return true;
        case 17: pp->distance = string2double(value); return true;
        case 18: pp->meanDistanceNeighbourood = string2double(value); return true;
        case 19: pp->approaching = string2double(value); return true;
        case 20: pp->meanApproachingNeighbourood = string2double(value); return true;
        case 21: pp->nodeDegree = string2long(value); return true;
        case 22: pp->meanNodeDegreeNeighbourood = string2double(value); return true;
        case 23: pp->nodeDegreeVariance = string2double(value); return true;
        case 24: pp->meanNodeDegreeVarianceNeighbourood = string2double(value); return true;
        case 25: pp->meanSnrNeighbourood = string2double(value); return true;
        case 26: pp->snrNeighbourood = string2double(value); return true;
        case 27: pp->meanPowNeighbourood = string2double(value); return true;
        case 28: pp->powNeighbourood = string2double(value); return true;
        case 29: pp->meanPerNeighbourood = string2double(value); return true;
        case 30: pp->perNeighbourood = string2double(value); return true;
        case 31: pp->queueMacSizeAbs = string2double(value); return true;
        case 32: pp->meanQueueMacSizeAbsNeighbourood = string2double(value); return true;
        case 33: pp->queueMacSizePerc = string2double(value); return true;
        case 34: pp->meanQueueMacSizePercNeighbourood = string2double(value); return true;
        case 35: pp->l3Metric = string2double(value); return true;
        case 36: pp->meanL3MetricNeighbourood = string2double(value); return true;
        case 37: pp->througputMeanSecWindow = string2double(value); return true;
        case 38: pp->througputVarSecWindow = string2double(value); return true;
        case 39: pp->througputMeanNumWindow = string2double(value); return true;
        case 40: pp->througputVarNumWindow = string2double(value); return true;
        case 41: pp->meanThrougputMeanSecWindowNeighbourood = string2double(value); return true;
        case 42: pp->meanThrougputVarSecWindowNeighbourood = string2double(value); return true;
        case 43: pp->meanThrougputMeanNumWindowNeighbourood = string2double(value); return true;
        case 44: pp->meanThrougputVarNumWindowNeighbourood = string2double(value); return true;
        case 45: pp->througputMeanTrendSecWindow = string2double(value); return true;
        case 46: pp->meanThrougputMeanTrendSecWindowNeighbourood = string2double(value); return true;
        case 47: pp->delayMeanSecWindow = string2double(value); return true;
        case 48: pp->delayVarSecWindow = string2double(value); return true;
        case 49: pp->delayMeanNumWindow = string2double(value); return true;
        case 50: pp->delayVarNumWindow = string2double(value); return true;
        case 51: pp->meanDelayMeanSecWindowNeighbourood = string2double(value); return true;
        case 52: pp->meanDelayVarSecWindowNeighbourood = string2double(value); return true;
        case 53: pp->meanDelayMeanNumWindowNeighbourood = string2double(value); return true;
        case 54: pp->meanDelayVarNumWindowNeighbourood = string2double(value); return true;
        case 55: pp->delayMeanTrendSecWindow = string2double(value); return true;
        case 56: pp->meanDelayMeanTrendSecWindowNeighbourood = string2double(value); return true;
        case 57: pp->pdrSecWindow = string2double(value); return true;
        case 58: pp->pdrNumWindow = string2double(value); return true;
        case 59: pp->meanPdrSecWindowNeighbourood = string2double(value); return true;
        case 60: pp->meanPdrNumWindowNeighbourood = string2double(value); return true;
        case 61: pp->pdrTrendSecWindow = string2double(value); return true;
        case 62: pp->meanPdrTrendSecWindowNeighbourood = string2double(value); return true;
        case 63: pp->nextHopDistance = string2double(value); return true;
        case 64: pp->meanNextHopDistanceNeighbourood = string2double(value); return true;
        case 65: pp->nextHopApproaching = string2double(value); return true;
        case 66: pp->meanNextHopApproachingNeighbourood = string2double(value); return true;
        default: return false;
    }
}

const char *nodeinfoDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 0: return omnetpp::opp_typename(typeid(L3Address));
        case 2: return omnetpp::opp_typename(typeid(Coord));
        case 3: return omnetpp::opp_typename(typeid(Coord));
        case 4: return omnetpp::opp_typename(typeid(Coord));
        default: return nullptr;
    };
}

void *nodeinfoDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    nodeinfo *pp = (nodeinfo *)object; (void)pp;
    switch (field) {
        case 0: return (void *)(&pp->localAddr); break;
        case 2: return (void *)(&pp->pos); break;
        case 3: return (void *)(&pp->velocity); break;
        case 4: return (void *)(&pp->meanVelocityNeighbourood); break;
        default: return nullptr;
    }
}

Register_Class(ApplicationPacketExt)

ApplicationPacketExt::ApplicationPacketExt(const char *name, short kind) : ::omnetpp::cPacket(name,kind)
{
    this->sequenceNumber = 0;
    neighbours_arraysize = 0;
    this->neighbours = 0;
}

ApplicationPacketExt::ApplicationPacketExt(const ApplicationPacketExt& other) : ::omnetpp::cPacket(other)
{
    neighbours_arraysize = 0;
    this->neighbours = 0;
    copy(other);
}

ApplicationPacketExt::~ApplicationPacketExt()
{
    delete [] this->neighbours;
}

ApplicationPacketExt& ApplicationPacketExt::operator=(const ApplicationPacketExt& other)
{
    if (this==&other) return *this;
    ::omnetpp::cPacket::operator=(other);
    copy(other);
    return *this;
}

void ApplicationPacketExt::copy(const ApplicationPacketExt& other)
{
    this->sequenceNumber = other.sequenceNumber;
    this->myInfo = other.myInfo;
    this->nextInfo = other.nextInfo;
    delete [] this->neighbours;
    this->neighbours = (other.neighbours_arraysize==0) ? nullptr : new nodeinfo[other.neighbours_arraysize];
    neighbours_arraysize = other.neighbours_arraysize;
    for (unsigned int i=0; i<neighbours_arraysize; i++)
        this->neighbours[i] = other.neighbours[i];
}

void ApplicationPacketExt::parsimPack(omnetpp::cCommBuffer *b) const
{
    ::omnetpp::cPacket::parsimPack(b);
    doParsimPacking(b,this->sequenceNumber);
    doParsimPacking(b,this->myInfo);
    doParsimPacking(b,this->nextInfo);
    b->pack(neighbours_arraysize);
    doParsimArrayPacking(b,this->neighbours,neighbours_arraysize);
}

void ApplicationPacketExt::parsimUnpack(omnetpp::cCommBuffer *b)
{
    ::omnetpp::cPacket::parsimUnpack(b);
    doParsimUnpacking(b,this->sequenceNumber);
    doParsimUnpacking(b,this->myInfo);
    doParsimUnpacking(b,this->nextInfo);
    delete [] this->neighbours;
    b->unpack(neighbours_arraysize);
    if (neighbours_arraysize==0) {
        this->neighbours = 0;
    } else {
        this->neighbours = new nodeinfo[neighbours_arraysize];
        doParsimArrayUnpacking(b,this->neighbours,neighbours_arraysize);
    }
}

long ApplicationPacketExt::getSequenceNumber() const
{
    return this->sequenceNumber;
}

void ApplicationPacketExt::setSequenceNumber(long sequenceNumber)
{
    this->sequenceNumber = sequenceNumber;
}

nodeinfo& ApplicationPacketExt::getMyInfo()
{
    return this->myInfo;
}

void ApplicationPacketExt::setMyInfo(const nodeinfo& myInfo)
{
    this->myInfo = myInfo;
}

nodeinfo& ApplicationPacketExt::getNextInfo()
{
    return this->nextInfo;
}

void ApplicationPacketExt::setNextInfo(const nodeinfo& nextInfo)
{
    this->nextInfo = nextInfo;
}

void ApplicationPacketExt::setNeighboursArraySize(unsigned int size)
{
    nodeinfo *neighbours2 = (size==0) ? nullptr : new nodeinfo[size];
    unsigned int sz = neighbours_arraysize < size ? neighbours_arraysize : size;
    for (unsigned int i=0; i<sz; i++)
        neighbours2[i] = this->neighbours[i];
    neighbours_arraysize = size;
    delete [] this->neighbours;
    this->neighbours = neighbours2;
}

unsigned int ApplicationPacketExt::getNeighboursArraySize() const
{
    return neighbours_arraysize;
}

nodeinfo& ApplicationPacketExt::getNeighbours(unsigned int k)
{
    if (k>=neighbours_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", neighbours_arraysize, k);
    return this->neighbours[k];
}

void ApplicationPacketExt::setNeighbours(unsigned int k, const nodeinfo& neighbours)
{
    if (k>=neighbours_arraysize) throw omnetpp::cRuntimeError("Array of size %d indexed by %d", neighbours_arraysize, k);
    this->neighbours[k] = neighbours;
}

class ApplicationPacketExtDescriptor : public omnetpp::cClassDescriptor
{
  private:
    mutable const char **propertynames;
  public:
    ApplicationPacketExtDescriptor();
    virtual ~ApplicationPacketExtDescriptor();

    virtual bool doesSupport(omnetpp::cObject *obj) const override;
    virtual const char **getPropertyNames() const override;
    virtual const char *getProperty(const char *propertyname) const override;
    virtual int getFieldCount() const override;
    virtual const char *getFieldName(int field) const override;
    virtual int findField(const char *fieldName) const override;
    virtual unsigned int getFieldTypeFlags(int field) const override;
    virtual const char *getFieldTypeString(int field) const override;
    virtual const char **getFieldPropertyNames(int field) const override;
    virtual const char *getFieldProperty(int field, const char *propertyname) const override;
    virtual int getFieldArraySize(void *object, int field) const override;

    virtual const char *getFieldDynamicTypeString(void *object, int field, int i) const override;
    virtual std::string getFieldValueAsString(void *object, int field, int i) const override;
    virtual bool setFieldValueAsString(void *object, int field, int i, const char *value) const override;

    virtual const char *getFieldStructName(int field) const override;
    virtual void *getFieldStructValuePointer(void *object, int field, int i) const override;
};

Register_ClassDescriptor(ApplicationPacketExtDescriptor)

ApplicationPacketExtDescriptor::ApplicationPacketExtDescriptor() : omnetpp::cClassDescriptor("inet::ApplicationPacketExt", "omnetpp::cPacket")
{
    propertynames = nullptr;
}

ApplicationPacketExtDescriptor::~ApplicationPacketExtDescriptor()
{
    delete[] propertynames;
}

bool ApplicationPacketExtDescriptor::doesSupport(omnetpp::cObject *obj) const
{
    return dynamic_cast<ApplicationPacketExt *>(obj)!=nullptr;
}

const char **ApplicationPacketExtDescriptor::getPropertyNames() const
{
    if (!propertynames) {
        static const char *names[] = {  nullptr };
        omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
        const char **basenames = basedesc ? basedesc->getPropertyNames() : nullptr;
        propertynames = mergeLists(basenames, names);
    }
    return propertynames;
}

const char *ApplicationPacketExtDescriptor::getProperty(const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? basedesc->getProperty(propertyname) : nullptr;
}

int ApplicationPacketExtDescriptor::getFieldCount() const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    return basedesc ? 4+basedesc->getFieldCount() : 4;
}

unsigned int ApplicationPacketExtDescriptor::getFieldTypeFlags(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeFlags(field);
        field -= basedesc->getFieldCount();
    }
    static unsigned int fieldTypeFlags[] = {
        FD_ISEDITABLE,
        FD_ISCOMPOUND,
        FD_ISCOMPOUND,
        FD_ISARRAY | FD_ISCOMPOUND,
    };
    return (field>=0 && field<4) ? fieldTypeFlags[field] : 0;
}

const char *ApplicationPacketExtDescriptor::getFieldName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldName(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldNames[] = {
        "sequenceNumber",
        "myInfo",
        "nextInfo",
        "neighbours",
    };
    return (field>=0 && field<4) ? fieldNames[field] : nullptr;
}

int ApplicationPacketExtDescriptor::findField(const char *fieldName) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    int base = basedesc ? basedesc->getFieldCount() : 0;
    if (fieldName[0]=='s' && strcmp(fieldName, "sequenceNumber")==0) return base+0;
    if (fieldName[0]=='m' && strcmp(fieldName, "myInfo")==0) return base+1;
    if (fieldName[0]=='n' && strcmp(fieldName, "nextInfo")==0) return base+2;
    if (fieldName[0]=='n' && strcmp(fieldName, "neighbours")==0) return base+3;
    return basedesc ? basedesc->findField(fieldName) : -1;
}

const char *ApplicationPacketExtDescriptor::getFieldTypeString(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldTypeString(field);
        field -= basedesc->getFieldCount();
    }
    static const char *fieldTypeStrings[] = {
        "long",
        "nodeinfo",
        "nodeinfo",
        "nodeinfo",
    };
    return (field>=0 && field<4) ? fieldTypeStrings[field] : nullptr;
}

const char **ApplicationPacketExtDescriptor::getFieldPropertyNames(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldPropertyNames(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

const char *ApplicationPacketExtDescriptor::getFieldProperty(int field, const char *propertyname) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldProperty(field, propertyname);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        default: return nullptr;
    }
}

int ApplicationPacketExtDescriptor::getFieldArraySize(void *object, int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldArraySize(object, field);
        field -= basedesc->getFieldCount();
    }
    ApplicationPacketExt *pp = (ApplicationPacketExt *)object; (void)pp;
    switch (field) {
        case 3: return pp->getNeighboursArraySize();
        default: return 0;
    }
}

const char *ApplicationPacketExtDescriptor::getFieldDynamicTypeString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldDynamicTypeString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ApplicationPacketExt *pp = (ApplicationPacketExt *)object; (void)pp;
    switch (field) {
        default: return nullptr;
    }
}

std::string ApplicationPacketExtDescriptor::getFieldValueAsString(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldValueAsString(object,field,i);
        field -= basedesc->getFieldCount();
    }
    ApplicationPacketExt *pp = (ApplicationPacketExt *)object; (void)pp;
    switch (field) {
        case 0: return long2string(pp->getSequenceNumber());
        case 1: {std::stringstream out; out << pp->getMyInfo(); return out.str();}
        case 2: {std::stringstream out; out << pp->getNextInfo(); return out.str();}
        case 3: {std::stringstream out; out << pp->getNeighbours(i); return out.str();}
        default: return "";
    }
}

bool ApplicationPacketExtDescriptor::setFieldValueAsString(void *object, int field, int i, const char *value) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->setFieldValueAsString(object,field,i,value);
        field -= basedesc->getFieldCount();
    }
    ApplicationPacketExt *pp = (ApplicationPacketExt *)object; (void)pp;
    switch (field) {
        case 0: pp->setSequenceNumber(string2long(value)); return true;
        default: return false;
    }
}

const char *ApplicationPacketExtDescriptor::getFieldStructName(int field) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructName(field);
        field -= basedesc->getFieldCount();
    }
    switch (field) {
        case 1: return omnetpp::opp_typename(typeid(nodeinfo));
        case 2: return omnetpp::opp_typename(typeid(nodeinfo));
        case 3: return omnetpp::opp_typename(typeid(nodeinfo));
        default: return nullptr;
    };
}

void *ApplicationPacketExtDescriptor::getFieldStructValuePointer(void *object, int field, int i) const
{
    omnetpp::cClassDescriptor *basedesc = getBaseClassDescriptor();
    if (basedesc) {
        if (field < basedesc->getFieldCount())
            return basedesc->getFieldStructValuePointer(object, field, i);
        field -= basedesc->getFieldCount();
    }
    ApplicationPacketExt *pp = (ApplicationPacketExt *)object; (void)pp;
    switch (field) {
        case 1: return (void *)(&pp->getMyInfo()); break;
        case 2: return (void *)(&pp->getNextInfo()); break;
        case 3: return (void *)(&pp->getNeighbours(i)); break;
        default: return nullptr;
    }
}

} // namespace inet

