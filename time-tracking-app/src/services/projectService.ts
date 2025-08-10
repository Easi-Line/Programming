import { Project } from '../models/project';

export class ProjectService {
    private projects: Project[] = [];

    public createProject(project: Project): Project {
        this.projects.push(project);
        return project;
    }

    public fetchProjects(): Project[] {
        return this.projects;
    }

    public updateProject(updatedProject: Project): Project | null {
        const index = this.projects.findIndex(project => project.id === updatedProject.id);
        if (index !== -1) {
            this.projects[index] = updatedProject;
            return updatedProject;
        }
        return null;
    }
}