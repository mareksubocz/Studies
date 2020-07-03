import React from 'react';
import ToDoList from './ToDoList';
import tasksData from './tasksData';
import Task from './Task';

class App extends React.Component {
  constructor() {
      super()
      this.state = {
          tasks: tasksData
      }
      this.handleChange = this.handleChange.bind(this)
  }
  
  handleChange(id) {
      this.setState(prevState => {
          const updatedTodos = prevState.todos.map(todo => {
              if (todo.id === id) {
                  todo.completed = !todo.completed
              }
              return todo
          })
          return {
              tasks: updatedTodos
          }
      })
  }
  
  render() {
    const taskItems = this.state.tasks.map(task => <Task key={task.id} text = {task.text} zaliczone={task.completed} onCheckboxChange={this.onCheckboxChange}/>)

    return (
      <div className="App">
        <header className="App-header">
          <h1>Welcome to my To Do list!</h1>
          <ToDoList tasks = {taskItems} onChange={this.onCheckboxChange}/>
        </header>
      </div>
    );  
  }
}

export default App;
