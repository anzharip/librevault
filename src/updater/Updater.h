/* Copyright (C) 2015-2016 Alexander Shishenko <GamePad64@gmail.com>
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
 */
#pragma once
#include "src/pch.h"
#include <QObject>

class AbstractUpdater : public QObject {
Q_OBJECT

public:
	AbstractUpdater(QObject* parent);

public slots:

private:
};

#if defined(Q_OS_WIN)
class WinUpdater : public AbstractUpdater {
Q_OBJECT

public:
	WinUpdater(QObject* parent);
};
using Updater = WinUpdater;

#elif defined(Q_OS_MAC)
class MacUpdater : public AbstractUpdater {
Q_OBJECT

public:
	MacUpdater(QObject* parent);
};
using Updater = MacUpdater;
#endif
