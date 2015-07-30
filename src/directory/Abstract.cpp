/* Copyright (C) 2015 Alexander Shishenko <GamePad64@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include "DirectoryExchanger.h"
#include "../Session.h"
#include "Abstract.h"

namespace librevault {

AbstractProvider::AbstractProvider(Session& session, DirectoryExchanger& exchanger) : log_(spdlog::get("Librevault")), session_(session), exchanger_(exchanger) {}
AbstractProvider::~AbstractProvider() {}

AbstractDirectory::AbstractDirectory(Session& session, AbstractProvider& provider) : log_(spdlog::get("Librevault")), session_(session), provider_(provider), exchanger_(provider.exchanger()) {}
AbstractDirectory::~AbstractDirectory() {}

} /* namespace librevault */
