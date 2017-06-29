//
// Generated file, do not edit! Created by nedtool 5.0 from inet/applications/base/ApplicationPacketExt.msg.
//

#ifndef __INET_APPLICATIONPACKETEXT_M_H
#define __INET_APPLICATIONPACKETEXT_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0500
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// cplusplus {{
#include "inet/networklayer/common/L3Address.h"
#include "inet/common/geometry/common/Coord.h"
#include <list>
// }}


namespace inet {

/**
 * Struct generated from inet/applications/base/ApplicationPacketExt.msg:29 by nedtool.
 */
struct nodeinfo
{
    nodeinfo();
    L3Address localAddr;
    int appAddr;
    Coord pos;
    Coord velocity;
    Coord meanVelocityNeighbourood;
    double velTheta;
    double meanVelThetaNeighbourood;
    double velThetaVariance;
    double velThetaMean;
    double meanVelThetaVarianceNeighbourood;
    double meanVelThetaMeanNeighbourood;
    double velLength;
    double meanVelLengthNeighbourood;
    double velLengthVariance;
    double velLengthMean;
    double meanVelLengthVarianceNeighbourood;
    double meanVelLengthMeanNeighbourood;
    double distance;
    double meanDistanceNeighbourood;
    double approaching;
    double meanApproachingNeighbourood;
    int nodeDegree;
    double meanNodeDegreeNeighbourood;
    double nodeDegreeVariance;
    double meanNodeDegreeVarianceNeighbourood;
    double meanSnrNeighbourood;
    double snrNeighbourood;
    double meanPowNeighbourood;
    double powNeighbourood;
    double meanPerNeighbourood;
    double perNeighbourood;
    double queueMacSizeAbs;
    double meanQueueMacSizeAbsNeighbourood;
    double queueMacSizePerc;
    double meanQueueMacSizePercNeighbourood;
    double l3Metric;
    double meanL3MetricNeighbourood;
    double througputMeanSecWindow;
    double througputVarSecWindow;
    double througputMeanNumWindow;
    double througputVarNumWindow;
    double meanThrougputMeanSecWindowNeighbourood;
    double meanThrougputVarSecWindowNeighbourood;
    double meanThrougputMeanNumWindowNeighbourood;
    double meanThrougputVarNumWindowNeighbourood;
    double througputMeanTrendSecWindow;
    double meanThrougputMeanTrendSecWindowNeighbourood;
    double delayMeanSecWindow;
    double delayVarSecWindow;
    double delayMeanNumWindow;
    double delayVarNumWindow;
    double meanDelayMeanSecWindowNeighbourood;
    double meanDelayVarSecWindowNeighbourood;
    double meanDelayMeanNumWindowNeighbourood;
    double meanDelayVarNumWindowNeighbourood;
    double delayMeanTrendSecWindow;
    double meanDelayMeanTrendSecWindowNeighbourood;
    double pdrSecWindow;
    double pdrNumWindow;
    double meanPdrSecWindowNeighbourood;
    double meanPdrNumWindowNeighbourood;
    double pdrTrendSecWindow;
    double meanPdrTrendSecWindowNeighbourood;
    double nextHopDistance;
    double meanNextHopDistanceNeighbourood;
    double nextHopApproaching;
    double meanNextHopApproachingNeighbourood;
};

// helpers for local use
void __doPacking(omnetpp::cCommBuffer *b, const nodeinfo& a);
void __doUnpacking(omnetpp::cCommBuffer *b, nodeinfo& a);

inline void doParsimPacking(omnetpp::cCommBuffer *b, const nodeinfo& obj) { __doPacking(b, obj); }
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, nodeinfo& obj) { __doUnpacking(b, obj); }

/**
 * Class generated from <tt>inet/applications/base/ApplicationPacketExt.msg:119</tt> by nedtool.
 * <pre>
 * packet ApplicationPacketExt
 * {
 *     long sequenceNumber;
 * 
 *     nodeinfo myInfo;
 *     nodeinfo nextInfo;
 * 
 *     //int nodeDegree;
 *     //double meanSnrNeighbourood;
 * 	//double meanPowNeighbourood;	
 * 
 *     nodeinfo neighbours[];
 * }
 * </pre>
 */
class ApplicationPacketExt : public ::omnetpp::cPacket
{
  protected:
    long sequenceNumber;
    nodeinfo myInfo;
    nodeinfo nextInfo;
    nodeinfo *neighbours; // array ptr
    unsigned int neighbours_arraysize;

  private:
    void copy(const ApplicationPacketExt& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const ApplicationPacketExt&);

  public:
    ApplicationPacketExt(const char *name=nullptr, int kind=0);
    ApplicationPacketExt(const ApplicationPacketExt& other);
    virtual ~ApplicationPacketExt();
    ApplicationPacketExt& operator=(const ApplicationPacketExt& other);
    virtual ApplicationPacketExt *dup() const {return new ApplicationPacketExt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b);

    // field getter/setter methods
    virtual long getSequenceNumber() const;
    virtual void setSequenceNumber(long sequenceNumber);
    virtual nodeinfo& getMyInfo();
    virtual const nodeinfo& getMyInfo() const {return const_cast<ApplicationPacketExt*>(this)->getMyInfo();}
    virtual void setMyInfo(const nodeinfo& myInfo);
    virtual nodeinfo& getNextInfo();
    virtual const nodeinfo& getNextInfo() const {return const_cast<ApplicationPacketExt*>(this)->getNextInfo();}
    virtual void setNextInfo(const nodeinfo& nextInfo);
    virtual void setNeighboursArraySize(unsigned int size);
    virtual unsigned int getNeighboursArraySize() const;
    virtual nodeinfo& getNeighbours(unsigned int k);
    virtual const nodeinfo& getNeighbours(unsigned int k) const {return const_cast<ApplicationPacketExt*>(this)->getNeighbours(k);}
    virtual void setNeighbours(unsigned int k, const nodeinfo& neighbours);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const ApplicationPacketExt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, ApplicationPacketExt& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_APPLICATIONPACKETEXT_M_H
