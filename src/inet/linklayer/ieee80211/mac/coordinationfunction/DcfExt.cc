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

#include "DcfExt.h"
#include "inet/common/ModuleAccess.h"
#include "inet/linklayer/ieee80211/mac/framesequence/DcfFs.h"
#include "inet/linklayer/ieee80211/mac/Ieee80211Mac.h"
#include "inet/linklayer/ieee80211/mac/rateselection/RateSelection.h"
#include "inet/linklayer/ieee80211/mac/recipient/RecipientAckProcedure.h"

#include "Ieee802CtrlExt.h"

namespace inet {
namespace ieee80211 {

Define_Module(DcfExt);

void DcfExt::recipientProcessReceivedFrame(Ieee80211Frame* frame)
{

    Ieee80211ReceptionIndication *c = check_and_cast<Ieee80211ReceptionIndication *>(frame->removeControlInfo());

    if (c) {
        Ieee802CtrlExt *ctrl = new Ieee802CtrlExt();
        ctrl->setRcvPow(c->getRecPow());
        ctrl->setRcvSnr(c->getSnr());
        ctrl->setRcvPER(c->getPacketErrorRate());

        ctrl->setQueueMacAbs(pendingQueue->getLength());
        ctrl->setQueueMacPerc(((double) pendingQueue->getLength()) / ((double) pendingQueue->getMaxQueueSize()));

        frame->setControlInfo(ctrl);      // ADDED by Angelo Trotta
    }

    if (auto dataOrMgmtFrame = dynamic_cast<Ieee80211DataOrMgmtFrame *>(frame))
        recipientAckProcedure->processReceivedFrame(dataOrMgmtFrame, recipientAckPolicy, this);
    if (auto dataFrame = dynamic_cast<Ieee80211DataFrame*>(frame))
        sendUp(recipientDataService->dataFrameReceived(dataFrame));
    else if (auto mgmtFrame = dynamic_cast<Ieee80211ManagementFrame*>(frame))
        sendUp(recipientDataService->managementFrameReceived(mgmtFrame));
    else { // TODO: else if (auto ctrlFrame = dynamic_cast<Ieee80211ControlFrame*>(frame))
        sendUp(recipientDataService->controlFrameReceived(frame));
        recipientProcessControlFrame(frame);
        delete frame;
    }
}

DcfExt::~DcfExt()
{
}

} // namespace ieee80211
} // namespace inet

