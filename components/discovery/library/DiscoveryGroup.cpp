/* Copyright (C) 2016 Alexander Shishenko <alex@shishenko.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
#include "DiscoveryGroup.h"
#include "Discovery.h"
#include "multicast/MulticastGroup.h"
#include "multicast/MulticastProvider.h"
#include "mldht/MLDHTGroup.h"
#include "mldht/MLDHTProvider.h"
//#include "bttracker/BTTrackerGroup.h"
//#include "bttracker/BTTrackerProvider.h"

namespace librevault {

DiscoveryGroup::DiscoveryGroup(QByteArray id, MulticastProvider* multicast, MLDHTProvider* dht, Discovery* parent) :
	QObject(parent) {
	multicast_group_ = new MulticastGroup(multicast, id);
	dht_group_ = new MLDHTGroup(dht, id);

	connect(multicast_group_, &MulticastGroup::discovered, this, &DiscoveryGroup::discovered);
	connect(dht_group_, &MLDHTGroup::discovered, this, &DiscoveryGroup::discovered);
}

DiscoveryGroup::~DiscoveryGroup() {}

void DiscoveryGroup::setMulticastEnabled(bool enabled){
	multicast_group_->setEnabled(enabled);
}

void DiscoveryGroup::setMulticastInterval(std::chrono::seconds interval) {
	multicast_group_->setInterval(interval);
}

void DiscoveryGroup::setDHTEnabled(bool enabled) {
	dht_group_->setEnabled(enabled);
}

} /* namespace librevault */
