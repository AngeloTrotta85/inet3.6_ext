//
// Copyright (C) 2016 OpenSim Ltd.
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU Lesser General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU Lesser General Public License for more details.
//
// You should have received a copy of the GNU Lesser General Public License
// along with this program.  If not, see http://www.gnu.org/licenses/.
//

#ifndef __INET_DCFEXT_H
#define __INET_DCFEXT_H

#include "inet/linklayer/ieee80211/mac/coordinationfunction/Dcf.h"

namespace inet {
namespace ieee80211 {

/**
 * Implements IEEE 802.11 Distributed Coordination Function.
 */
class INET_API DcfExt : public Dcf
{
    protected:
        virtual void recipientProcessReceivedFrame(Ieee80211Frame *frame);

    public:
        virtual ~DcfExt();


        virtual double getQueuePerc() {return (((double) pendingQueue->getLength()) / ((double) pendingQueue->getMaxQueueSize()));}
        virtual double getQueueAbs() {return pendingQueue->getLength();}
};

} /* namespace ieee80211 */
} /* namespace inet */

#endif // ifndef __INET_DCFEXT_H
