/*
 Copyright (C) 2010-2013 Kristian Duske
 
 This file is part of TrenchBroom.
 
 TrenchBroom is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.
 
 TrenchBroom is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.
 
 You should have received a copy of the GNU General Public License
 along with TrenchBroom.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "ControllerFacade.h"

#include "Controller/NewDocumentCommand.h"
#include "Controller/OpenDocumentCommand.h"

namespace TrenchBroom {
    namespace Controller {
        void ControllerFacade::addCommandListener(CommandListener::Ptr listener) {
            m_commandProcessor.addCommandListener(listener);
        }
        
        void ControllerFacade::removeCommandListener(CommandListener::Ptr listener) {
            m_commandProcessor.removeCommandListener(listener);
        }

        bool ControllerFacade::newDocument(View::MapDocument::Ptr document, Model::Game::Ptr game) {
            Command::Ptr command = Command::Ptr(new NewDocumentCommand(document, game));
            return m_commandProcessor.submitCommand(command);
        }
        
        bool ControllerFacade::openDocument(View::MapDocument::Ptr document, Model::Game::Ptr game, const IO::Path& path) {
            Command::Ptr command = Command::Ptr(new OpenDocumentCommand(document, game, path));
            return m_commandProcessor.submitCommand(command);
        }
    }
}
