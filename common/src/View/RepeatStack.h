/*
 Copyright (C) 2020 Kristian Duske

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
 along with TrenchBroom. If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef TrenchBroom_RepeatStack
#define TrenchBroom_RepeatStack

#include <functional>
#include <vector>

namespace TrenchBroom {
    namespace View {
        class RepeatStack {
        public:
            using RepeatableAction = std::function<void()>;
        private:
            std::vector<RepeatableAction> m_stack;
            bool m_clearOnNextPush;
            mutable bool m_repeating;
        public:
            /**
             * Creates a new instance.
             */
            RepeatStack();

            /**
             * Returns the number of repeatable actions on this repeat stack.
             */
            size_t size() const;

            /**
             * Adds the given repeatable action to this repeat stack.
             * 
             * If this stack is currently repeating actions, the given action is not added.
             * 
             * @param repeatableAction the action to add
             */
            void push(RepeatableAction repeatableAction);

            /**
             * Repeats the actions on this stack in the order in which they were added.
             */
            void repeat() const;

            /**
             * Clears all repeatable actions on this stack.
             * 
             * The stack must not be repeating actions when this function is called.
             */ 
            void clear();

            /**
             * Prime the stack so that it is cleared when the next action is pushed.
             */
            void clearOnNextPush();
        };
    }
}

#endif /* defined(TrenchBroom_RepeatStack) */
