//
// Generated file, do not edit! Created by nedtool 5.1 from inet/transportlayer/contract/udp/UDPDataIndicationExt.msg.
//

#if defined(__clang__)
#  pragma clang diagnostic ignored "-Wreserved-id-macro"
#endif
#ifndef __INET_UDPDATAINDICATIONEXT_M_H
#define __INET_UDPDATAINDICATIONEXT_M_H

#include <omnetpp.h>

// nedtool version check
#define MSGC_VERSION 0x0501
#if (MSGC_VERSION!=OMNETPP_VERSION)
#    error Version mismatch! Probably this file was generated by an earlier version of nedtool: 'make clean' should help.
#endif

// cplusplus {{
#include "inet/transportlayer/contract/udp/UDPControlInfo.h"
// }}


namespace inet {

/**
 * Class generated from <tt>inet/transportlayer/contract/udp/UDPDataIndicationExt.msg:25</tt> by nedtool.
 * <pre>
 * class UDPDataIndicationExt extends UDPDataIndication
 * {
 *     double snr;
 *     double pow;
 *     double per;
 *     double queueMacPerc;
 *     double queueMacAbs;
 * }
 * </pre>
 */
class UDPDataIndicationExt : public ::inet::UDPDataIndication
{
  protected:
    double snr;
    double pow;
    double per;
    double queueMacPerc;
    double queueMacAbs;

  private:
    void copy(const UDPDataIndicationExt& other);

  protected:
    // protected and unimplemented operator==(), to prevent accidental usage
    bool operator==(const UDPDataIndicationExt&);

  public:
    UDPDataIndicationExt();
    UDPDataIndicationExt(const UDPDataIndicationExt& other);
    virtual ~UDPDataIndicationExt();
    UDPDataIndicationExt& operator=(const UDPDataIndicationExt& other);
    virtual UDPDataIndicationExt *dup() const override {return new UDPDataIndicationExt(*this);}
    virtual void parsimPack(omnetpp::cCommBuffer *b) const override;
    virtual void parsimUnpack(omnetpp::cCommBuffer *b) override;

    // field getter/setter methods
    virtual double getSnr() const;
    virtual void setSnr(double snr);
    virtual double getPow() const;
    virtual void setPow(double pow);
    virtual double getPer() const;
    virtual void setPer(double per);
    virtual double getQueueMacPerc() const;
    virtual void setQueueMacPerc(double queueMacPerc);
    virtual double getQueueMacAbs() const;
    virtual void setQueueMacAbs(double queueMacAbs);
};

inline void doParsimPacking(omnetpp::cCommBuffer *b, const UDPDataIndicationExt& obj) {obj.parsimPack(b);}
inline void doParsimUnpacking(omnetpp::cCommBuffer *b, UDPDataIndicationExt& obj) {obj.parsimUnpack(b);}

} // namespace inet

#endif // ifndef __INET_UDPDATAINDICATIONEXT_M_H

